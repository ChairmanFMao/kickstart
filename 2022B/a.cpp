#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const long double PI = 3.14159265359;

void solve() {
	ll r, a, b;
	cin >> r >> a >> b;

	long double out = 0;
	ll count = 0;
	while (r > 0) {
		out += r*r*PI;
		if (count & 1)
			r /= b;
		else
			r *= a;
		count++;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << setprecision(20);
	int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}

