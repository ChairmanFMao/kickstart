#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// John is playing to minimize score

void solve() {
	int n;
	cin >> n;

	int current = n, out = 0;
	while (current >= 1) {
		out++;
		current -= 2;
		current -= 3;
	}

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

