#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I might just try to think of the O(n^2) algorithm for test
// set 1 and then implement that
// can be any number of swaps before processing
// just build upon previous moves?
// need points that map to themselves
// get all the cycle lengths earlier and then can change
// find the shortest distance to another cycle
// The current solution gets wa on test set 1
// Code still getting wa on test set 1
// I had an else if bit that was hindering my code
// but without it, I still get wa
// can just link smaller groups easily
// just like basic dp kinda?
// just really want to pass the first test set
// I didn't do the knapsack type dp right
// It was the right idea

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) {
		cin >> i; i--;
	}

	vector<ll> cycles(n+1,0), seen(n,0);
	for (int i = 0; i < n; i++) {
		if (seen[i])
			continue;
		queue<ll> q;
		ll current = 1;
		q.push(i);
		seen[i] = 1;
		while (sz(q)) {
			ll tmp = q.front();
			q.pop();
			if (!seen[a[tmp]]) {
				seen[a[tmp]] = 1;
				current++;
				q.push(a[tmp]);
			}
		}
		cycles[current]++;
	}

	/*
	cout << "cycles: ";
	for (int i = 0; i <= n; i++)
		cout << cycles[i] << " ";
	cout << "\n";
	*/

	// Stores the cost to get here through joining
	//vector<vector<ll>> dp(n+1,INT_MAX);
	//dp[0] = -1;
	vector<ll> v;
	for (int j = 0; j <= n; j++)
		for (int k = 0; k < cycles[j]; k++)
			v.push_back(j);
	// Does basic dp of a kind to try to link cycles
	reverse(all(v));
	/*
	for (int i = 0; i < sz(v); i++)
		for (int j = n; ~j; j--)
			if (j-v[i] >= 0 && dp[j-v[i]] != INT_MAX)
				dp[j] = min(dp[j],dp[j-v[i]]+1);

	for (int i = 0; i < n; i++)
		dp[i+1] = min(dp[i+1],dp[i]+1);
	*/
	/*
	cout << "dp: ";
	for (int i = 0; i <= n; i++)
		cout << dp[i] << " ";
	cout << "\n";
	*/

	// Want to gets ones of cycle length i
	for (int i = 1; i <= n; i++) {
		ll current = INT_MAX;
		// Checks if there already exists a cycle of length i
		if (cycles[i])
			current = 0;
		// This checks for larger ones to shrink
		
		for (ll j = i+1; j <= n; j++)
			if (cycles[j])
				current = min(current,1ll);
		// This uses the precalculated dp values
		//current = min(current,dp[i]);

		ll tmp = v[0], ptr = 1, moves = 0;
		while (tmp < i) {
			tmp += v[ptr];
			ptr++;
			moves++;
		}
		if (tmp > i)
			moves++;

		current = min(current,moves);
	
		cout << current << " ";
	}
	cout << "\n";
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

