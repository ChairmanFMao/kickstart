#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n, m, p;
	cin >> m >> n >> p;

	ll out = 0;
	vector<vector<ll> > grid(m,vector<ll>(n));
	for (vector<ll>& i : grid)
		for (ll& j : i)
			cin >> j;

	for (ll i = 0; i < n; i++) {
		ll big = 0;
		for (ll j = 0; j < m; j++)
			big = max(grid[j][i],big);
		out += big-grid[p-1][i];
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

