#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// median not mean

void solve() {
	int n, m;
	cin >> n >> m;
	vector<double> a(n);
	for (double& i : a)
		cin >> i;

	long double total = 0, out = 0;
	sort(all(a));
	for (int i = n-m+1; i < n; i++)
		out += a[i];

	if ((n-m) & 1)
		total = (a[(n-m)/2] + a[(n-m)/2 + 1]) / (double)2;
	else
		total = a[(n-m)/2];

	cout << out+total << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

