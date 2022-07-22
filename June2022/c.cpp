#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;

	vector<vector<int> > dp(n+1, vector<int>(26, 0));
	for (int i = 1; i <= n; i++) {
		dp[i][s[i-1]-65]++;
		for (int j = 0; j < 26; j++)
			dp[i][j] += dp[i-1][j];
	}

	int out = 0;
	for (int i = 0; i < q; i++) {
		int a, b, odd = 0;
		cin >> a >> b;
		for (int j = 0; j < 26; j++)
			if (abs(dp[a-1][j] - dp[b][j]) % 2)
				odd++;
		out += odd < 2 ? 1 : 0;
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
