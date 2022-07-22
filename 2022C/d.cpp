#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int MOD = 1e9 + 7;
ll ways, candies;

ll fact(int n) {
	ll out = 1;
	for (int i = 1; i <= n; i++)
		out *= i;
	return out;
}

bool pal(string s) {
	for (int i = 0; i < sz(s)/2; i++)
		if (s[i] != s[sz(s)-1-i])
			return 0;
	return 1;
}

void dfs(string s, bool first) {
	if (pal(s) && !first)
		candies += fact(sz(s));

	for (int i = 0; i < sz(s); i++) {
		dfs(s.substr(0,i) + s.substr(i+1), 0);
	}
}

void solve() {
	candies = 0;
	int n;
	string s;
	cin >> n >> s;
	ways = fact(n);
	
	dfs(s, 1);

	int d = __gcd(candies,ways);
	candies /= d;
	ways /= d;

	while (candies % ways)
		candies += MOD;
	cout << (candies / ways) % MOD << "\n";
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

