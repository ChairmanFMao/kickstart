#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Once we have all the prime factors of a we can multiply
// Very short time limit of 2 seconds

bool pal(ll n) {
	string s = to_string(n);
	for (int i = 0; i < sz(s)/2; i++) {
		if (s[i] != s[sz(s)-1-i])
			return 0;
	}
	return 1;
}

void solve() {
	ll a;
	cin >> a;

	ll out = 0;
	for (ll i = 1; i*i <= a; i++) {
		if (!(a % i)) {
			out += pal(i);
			if (i != a/i)
				out += pal(a/i);
		}
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

