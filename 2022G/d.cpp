#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// We are going to move down the tree and get O(n^2) I think
// push from the current flower to every other flower below
// have to consider the case where the butterfly stays on the same
// layer
// for each height we will go left to right, then right to left
// problem arises when you can't take multiple of the same one
// only change direction when moving down
// This should work on test set 1 and 2 but not 3

void solve() {
	ll n, e;
	cin >> n >> e;
	map<pair<ll,ll>,ll> m;
	for (int i = 0; i < n; i++) {
		ll a, b, c; cin >> a >> b >> c;
		m[{b,a}] = c;
	}

	// first two dimensions are for the grid
	// third vector is for direction, 0 is right, 1 is left
	// value is for the max nectar to get to that point
	vector<vector<vector<ll>> > grid(502,vector<vector<ll>>(501,vector<ll>(2,LONG_LONG_MIN)));

	ll out = 0;
	grid[501][0][0] = 0;
	for (int i = 501; i >= 0; i--) {
		for (int j = 0; j < 501; j++) {
			// This does moving to the right
			if (j < 500 && grid[i][j][0] != LONG_LONG_MIN)
				grid[i][j+1][0] = max(grid[i][j+1][0],grid[i][j][0]+m[{i,j+1}]);
			// This does moving down
			if (i) {
				grid[i-1][j][0] = max(grid[i-1][j][0],grid[i][j][0]+m[{i-1,j}]);
				if (grid[i][j][1] != LONG_LONG_MIN)
					grid[i-1][j][0] = max(grid[i-1][j][0],grid[i][j][1]-e+m[{i-1,j}]);
				grid[i-1][j][1] = max(grid[i-1][j][1],grid[i][j][1]+m[{i-1,j}]);
				if (grid[i][j][0] != LONG_LONG_MIN)
					grid[i-1][j][1] = max(grid[i-1][j][1],grid[i][j][0]-e+m[{i-1,j}]);
			}
		}
		for (int j = 500; j >= 0; j--) {
			// This does moving to the left
			if (j && grid[i][j][1] != LONG_LONG_MIN)
				grid[i][j-1][1] = max(grid[i][j-1][1],grid[i][j][1]+m[{i,j-1}]);
			// This does moving down
			if (i) {
				grid[i-1][j][0] = max(grid[i-1][j][0],grid[i][j][0]+m[{i-1,j}]);
				if (grid[i][j][1] != LONG_LONG_MIN)
					grid[i-1][j][0] = max(grid[i-1][j][0],grid[i][j][1]-e+m[{i-1,j}]);
				grid[i-1][j][1] = max(grid[i-1][j][1],grid[i][j][1]+m[{i-1,j}]);
				if (grid[i][j][0] != LONG_LONG_MIN)
					grid[i-1][j][1] = max(grid[i-1][j][1],grid[i][j][0]-e+m[{i-1,j}]);
			}

		}
	}

	for (int i = 0; i <= 501; i++)
		for (int j = 0; j <= 500; j++)
			for (int k = 0; k < 2; k++)
				out = max(out,grid[i][j][k]);

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

