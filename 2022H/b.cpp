#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this is just a nice dp problem
// there are 4 moves that you can do from each state
// can "take note of" the number of lilies in your basket
// I think that this might lead to O(n^2) somehow
// if you request too many none are dispensed
// unsure of a good way to get O(n log n) or smth
// just calculate from taking note at that point
// or could iterate over larger numbers
// I don't know if this is the right time complexity
// it passed first try!

void solve() {
	ll l;
	cin >> l;

	ll out = LONG_LONG_MAX;
	vector<ll> dp(l+1,LONG_LONG_MAX);
	dp[0] = 0;
	for (int i = 0; i < l; i++) {
		dp[i+1] = min(dp[i+1],dp[i]+1);
		if (!i)
			continue;
		for (int j = i; j <= l; j+=i)
			dp[j] = min(dp[j],dp[i]+((j-i)/i)*2 + 4);
	}

	cout << dp[l] << "\n";
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

