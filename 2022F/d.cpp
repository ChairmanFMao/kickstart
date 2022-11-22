#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// It should pass first test set and tle on second
// there will be 2e5 updates due to meetings
// at each point there may need to be n staff removed from meets
// priority queue might be too slow
// map of number of meetings to staff
// only need to iterate through the max number of distinct meets
// which is roughly 1e2.5
// just extend meetings by x-1 on right side?
// tle on the second part somehow
// checked tutorial and can be done with segtree I think

struct Segtree {
	vector<ll> tr;
	ll n;
	Segtree(vector<ll> v) {
		n = sz(v);
		tr.resize(n+n);
		for (ll i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (ll i = n-1; i > 0; i--)
			tr[i] = tr[i+i]+tr[i+i+1];
	}
 
	ll query(ll l, ll r) {
		ll out = 0;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out += tr[l++];
			if (!(r&1))
				out += tr[r--];
		}
		return out;
	}
 
	void update(ll pos, ll val) {
		tr[n+pos] += val;
		for (ll i = (n+pos)>>1; i > 0; i>>=1)
			tr[i] = tr[i+i]+tr[i+i+1];
	}
};

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
	return a.s < b.s;
}

void solve() {
	ll n, k, x, d, m;
	cin >> n >> k >> x >> d >> m;
	vector<pair<ll,ll> > mStart(m), mEnd(m);
	for (ll i = 0; i < m; i++) {
		ll p, l, r; cin >> p >> l >> r;
		mStart[i] = {p,l};
		mEnd[i] = {p,r+(x-1)};
	}

	sort(all(mStart),comp);
	sort(all(mEnd),comp);

	// Meets to staff and staff to meets maps
	map<ll,set<ll>> mtos;
	map<ll,ll> stom;
	vector<ll> pref(m+1,0), prev(m+1,0);
	for (ll i = 1; i <= n; i++) {
		mtos[0].insert(i);
		stom[i] = 0;
		pref[0]++;
	}

	Segtree prefix(pref);
	Segtree preval(prev);
	
	ll sptr = 0, eptr = 0;
	// This is linear time
	for (ll i = 0; i < x-1; i++) {
		while (sptr < m && mStart[sptr].s == i) {
			ll number = stom[mStart[sptr].f];
			mtos[number].erase(mStart[sptr].f);
			prefix.update(number, -1);
			preval.update(number, -number);
			prefix.update(number+1, 1);
			preval.update(number+1,number+1);
			mtos[number+1].insert(mStart[sptr].f);
			stom[mStart[sptr].f] = number+1;
			sptr++;
		}
		while (eptr < m && mEnd[eptr].s == i) {
			ll number = stom[mEnd[eptr].f];
			mtos[number].erase(mEnd[eptr].f);
			prefix.update(number, -1);
			preval.update(number, -number);
			prefix.update(number-1, 1);
			preval.update(number-1, number-1);
			mtos[number-1].insert(mEnd[eptr].f);
			stom[mEnd[eptr].f] = number-1;
			eptr++;
		}
	}

	// Need to make it a binary search
	// might need to use a segment tree
	// as the prefix sums aren't very good
	
	ll out = INT_MAX;
	// This is iterating over the ending time
	for (ll i = x-1; i < d; i++) {
		// This insertion and erasing should be n log n
		while (sptr < m && mStart[sptr].s == i) {
			ll number = stom[mStart[sptr].f];
			prefix.update(number, -1);
			preval.update(number, -number);
			prefix.update(number+1, 1);
			preval.update(number+1,number+1);
			mtos[number].erase(mStart[sptr].f);
			mtos[number+1].insert(mStart[sptr].f);
			stom[mStart[sptr].f] = number+1;
			sptr++;
		}

		while (eptr < m && mEnd[eptr].s == i) {
			ll number = stom[mEnd[eptr].f];
			prefix.update(number, -1);
			preval.update(number, -number);
			prefix.update(number-1, 1);
			preval.update(number-1, number-1);
			mtos[number].erase(mEnd[eptr].f);
			mtos[number-1].insert(mEnd[eptr].f);
			stom[mEnd[eptr].f] = number-1;
			eptr++;
		}

		// Turned out I just had the binary search wrong
		ll lower = 0, upper = m+1, mid = 0, pl = -1, pu = 0;
		while (lower < upper) {
			mid = (lower+upper)/2;
			if (lower == pl && upper == pu)
				break;
			pl = lower; pu = upper;
			if (prefix.query(0,mid) >= k)
				upper = mid;
			else
				lower = mid;
		}

		swap(lower,upper);

		out = min(out, preval.query(0,lower) - (prefix.query(0,lower)-k)*lower);
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

