#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// The ranges alter after operations are performed
// 30 second time limit and n <= 400
// Potentially coast of neighbor's operations and get closer
// wa on test 2, can't find counterexample yet
// Its not even a time or memory problem
// Didn't read the instructions carefully, there is a special condition
// I was solving a different problem
// Need to better way to choose to add or to subtract the numbers
// Tried just doing greedy with the next number but, it didn't work

const ll mxN = 400;
ll out = 0, n, d, e;
vector<ll> a(mxN, 0);

void solve() {
	out = 0;
	cin >> n >> d;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	e = n-1;
	for (int i = 0; i < n; i++) {
		while (e >= 0 && a[e] <= 0)
			e--;
		for (int j = i; j <= e; j++)
			while (a[j] < 0)
				a[j] += d;
	
		ll change = a[i] < d-a[i] ? -a[i] : d-a[i];
		out += abs(change);
		for (int j = i; j <= e; j++) {
			a[j] += change;
			if (a[j] >= d)
				a[j] %= d;
		}
		ll number = a[e];
		while (e >= 0 && a[e-1] >= number && a[e-1] < 0)
			e--;
	}
	
	cout << out;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}

