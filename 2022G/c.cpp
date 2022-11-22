#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// O(n^2) is not going to be possible, it will past test 1 only
// however the bounds on a are very small
// maybe something to do with segment trees but idk
// do dp on the sum value?
// trying dp with a map to make it a big faster
// getting mle, going to clear the maps to reduce memory
// binary search the ending point, doesnt work
// currently times out with bigger n and unique numbers
// calculate the min sum after each?
// Ideally want O(n max(a))
// at each number, each term uniquely maps onto another
// potentially precalculate ending ones at each stage?
// sort by maximum value that they will result in and
// sort them by the minimum value needed to perform
// potentially just brute force with some observations
// unsure if the a bound is useful or just to ensure that all the
// outputs would fit into a long long
// maybe square root decomposition?
// just do normally up to bound multiple, then go in parts
// when cant continue through parts do normally again
// I think that O(n sqrt n) should be fast enough but it gets wa
// on test set 2
// bound size of 2 doesnt work well for small inputs
// unsure about the tot and mult
// could actually just append extra zeros for right division
// put extra INT_MIN elements at the start of a?
// changed bound size to be greater and it doesnt work
// The numbers I get for larger test cases are too large
// I think it is something to do with the parts but i'm not sure
// Overestimating for some of them currently
// Finally works!
// This solution doesn't work in python as it is not fast enough
// I found this to be very educational and learn about sqrt
// decomposition even if it wasn't the intended method

string toString(__int128 num) {
    string str;
    do {
        int digit = num % 10;
        str = to_string(digit) + str;
        num = (num - digit) / 10;
    } while (num != 0);
    return str;
}

struct Part {
	__int128 tot, req, mult;
};

void solve() {
	__int128 n;
	ll n1;
	cin >> n1;
	n = n1;
	vector<__int128> a(n);
	for (__int128 i = 0; i < n; i++) {
		ll x; cin >> x;
		a[i] = x;
	}
	
	__int128 bound = 600;
	reverse(all(a));
	// Adds extra elements to ensure everythings fits into bounds
	while (n%bound) {
		n++;
		a.emplace_back(INT_MIN);
	}
	reverse(all(a));
	// Stores the minumum value needed and sum
	vector<Part> parts(n/bound);
	for (__int128 i = 0; i < n; i+=bound) {
		__int128 c = i/bound;
		parts[c].tot = 0;
		parts[c].req = 0;
		parts[c].mult = 0;
		for (__int128 j = i; j < i+bound; j++) {
			parts[c].mult += a[j]*(i+bound-j);
			parts[c].tot += a[j];
			parts[c].req = min(parts[c].req,parts[c].tot);
		}
	}

	__int128 out = 0;
	for (__int128 i = 0; i < n; i++) {
		__int128 subtot = 0;
		// Does the bit to get to a boundary
		vector<__int128> totals;
		__int128 current = 0, ctot = 0, pos = i;
		while (pos < n && pos % bound) {
			current += a[pos];
			if (current < 0)
				break;
			ctot += current;
			pos++;
		}
		if (current < 0) {
			subtot += ctot;
			out += subtot;
			continue;
		}
		// ctot is the the mult for the first bit
		subtot += ctot;
		totals.push_back(current);

		// Does the sqrt bit
		__int128 partPos = pos/bound;
		while (partPos < sz(parts)) {
			if (current + parts[partPos].req < 0)
				break;
			current += parts[partPos].tot;
			totals.push_back(parts[partPos].tot);
			subtot += parts[partPos].mult;
			partPos++;
		}

		__int128 lastTot = 0;
		pos = partPos*bound;
		// Does the ending bit
		while (pos < n) {
			current += a[pos];
			if (current < 0)
				break;
			lastTot += current;
			pos++;
		}
		subtot += lastTot;

		// lastTot contains extra occurs of the total earlier
		// so, offset should start at zero
		__int128 offset = 0;
		for (__int128 j = sz(totals)-1; ~j; j--) {
			subtot += offset*totals[j];
			offset += bound;
		}

		out += subtot;
	}

	cout << toString(out) << "\n";
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

