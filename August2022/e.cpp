#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 1e9+7;

// Find all possible pairs
// I think there will be a way to do this using dp
// both less than or equal to n
// This is O(n^2) and it won't pass test 2
// as the cap for n is 1e18, need a better approach
// something to do with mod k can narrow down the problem
// The only thing that matters is the values of i and j mod k
// However, k^2 is still 1e10 for test case 2
// I can think of a O(k^2) algorithm I think
// I might just try to implement it and see what happens
// maybe there actually is a way in O(k), with a map for all of
// the relations
// Currently have an O(k) ish algorithm however it counts all of
// the duplicates currently
// just remove the number of times that the lcm appears within
// the range?
// Currently underestimating the total
// Unsure how I am getting a runtime error
// can't seem to reproduce the runtime error
// There was this one error with k = 1 and index out of range
// This actually worked and passed everything!
// Very happy that I managed to get the idea and implementation
// :)

// Binary exponention, calculate powers in O(log exp) time
ll binExp(ll base, ll exp, ll m) {
	ll out = 1;
	for (ll i = exp; i > 0; i>>=1) {
		if (i & 1)
			out = (out * base) % m;
		base = (base * base) % m;
	}
	return out%m;
}

void solve() {
	ll a, b, n, k;
	cin >> a >> b >> n >> k;

	// Once we have the values we need to match them up
	// and check for validity
	// The case where i == j is also quite annoying
	
	vector<vector<ll> > dpa(k), dpb(k);
	for (ll i = 1; i <= min(n,k); i++) {
		dpa[binExp(i,a,k)].push_back(i);
		dpb[binExp(i,b,k)].push_back(i);
	}

	ll out = 0;
	for (ll i = 0; i < k; i++) {
		for (ll j : dpa[i]) {
			for (ll l : dpb[(k-i)%k]) {
				// this is the occurances of f
				ll fi = ((n-j)/k+1) % MOD;
				// this is the occurances of s
				ll si = ((n-l)/k+1) % MOD;
				// this is for the times that j == l
				if (l == j)
					fi--;
			
				ll add = (fi*si) % MOD;
				out = (out + add) % MOD;
			}
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

