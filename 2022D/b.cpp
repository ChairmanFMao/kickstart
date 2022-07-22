#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think that this is dp

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	ll m;
	cin >> m;
	vector<ll> b(m);
	for (ll& i : b)
		cin >> i;
	ll k;
	cin >> k;

	vector<ll> prefixA(n+1,0), prefixB(m+1,0);
	for (int i = 0; i < n; i++)
		prefixA[i+1] = prefixA[i] + a[i];
	for (int i = 0; i < m; i++)
		prefixB[i+1] = prefixB[i] + b[i];

	vector<ll> bestA(n+1,0), bestB(m+1,0);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			bestA[i] = max(bestA[i], prefixA[i-j] + prefixA[n] - prefixA[n-j]);
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= i; j++)
			bestB[i] = max(bestB[i], prefixB[i-j] + prefixB[m] - prefixB[m-j]);

	ll out = 0;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= i; j++)
			if (j <= m && i-j <= n)
				out = max(out, bestA[i-j] + bestB[j]);
	
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

