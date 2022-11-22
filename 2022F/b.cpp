#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Find the number completely filled after queries
// find the level of every container
// find the number of containers on each level and binary search?
// I don't think it matter where the water is added
const int mxN = 65535;
vector<vector<int> > adj(mxN);
vector<int> levels(mxN,0);
int n, q;

void dfs(int node, int parent, int level) {
	levels[level]++;
	for (int u : adj[node])
		if (u != parent)
			dfs(u, node, level+1);
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		levels[i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
	}

	dfs(0,0,0);

	int current = 0, best = 0;
	for (int i = 0; i < mxN; i++) {
		current += levels[i];
		if (current <= q)
			best += levels[i];
	}

	cout << best << "\n";
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

