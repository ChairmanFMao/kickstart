#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This is a dp problem, I should've recognised
// Followed the analysis to get a solution using dp in O(n m^2)
// Need to cache the closest to the left and right for each of the letters

void solve() {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int& i : s)
		cin >> i;
	int m;
	cin >> m;
	vector<int> k(m);
	for (int& i : k)
		cin >> i;

	map<int,vector<int> > pos;
	for (int i = 0; i < m; i++)
		pos[k[i]].push_back(i);

	vector<vector<ll> > dp(n+1, vector<ll>(m, INT_MAX));

	// I should be caching the closest to the left and right for the best
	// solution however, this managed to pass the tests!
	for (int i = 0; i < m; i++)
		dp[0][i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j : pos[s[i]]) {
			if (k[j] == s[i]) {
				// This finds the closest one to the right
				for (int l = j; l < m; l++)
					if (dp[i][l] != INT_MAX) {
						dp[i+1][j] = min(dp[i+1][j], dp[i][l] + abs(j-l));
						break;
					}
				// This finds the closest one to the left
				for (int l = j; ~l; l--)
					if (dp[i][l] != INT_MAX) {
						dp[i+1][j] = min(dp[i+1][j], dp[i][l] + abs(j-l));
						break;
					}
			}
		}
	}

	ll out = INT_MAX;
	for (int i = 0; i < m; i++)
		out = min(out, dp[n][i]);

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

