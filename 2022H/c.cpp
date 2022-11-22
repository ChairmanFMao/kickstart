#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Could do the simple O(n^2) way of starting from every node
// I will just code this up quickly for points
// This should time out on the second test case
// sort the nodes and move upwards from the bottom pits pushing
// values up the graph
// I think that this should work efficiently
// It passed and worked well

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	vector<vector<ll> > adj(n);
	for (ll i = 0; i < n-1; i++) {
		ll b, c; cin >> b >> c; b--; c--;
		adj[b].push_back(c);
		adj[c].push_back(b);
	}

	vector<ll> val(n,1);
	vector<pair<ll,ll> > v;
	for (int i = 0; i < n; i++)
		v.push_back({a[i],i});

	sort(all(v));

	for (int i = 0; i < n; i++)
		for (int u : adj[v[i].s])
			if (a[u] > v[i].f)
				val[u] += val[v[i].s];
	
	cout << *max_element(all(val)) << "\n";
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

