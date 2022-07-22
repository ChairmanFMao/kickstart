#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	
	ll total = 0;
	for (int i = 1; i <= n; i++)
		total += i;

	if (total % (x+y)) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	ll out = x * (total / (x+y));
	vector<ll> output;
	for (int i = n; i >= 1; i--) {
		if (out >= i) {
			out -= i;
			output.push_back(i);
		}
	}

	cout << "POSSIBLE\n";
	cout << sz(output) << "\n";
	for (ll i : output)
		cout << i << " ";
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

