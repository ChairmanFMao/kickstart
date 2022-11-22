#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// This code gets wa on test set 2
// code gets wa again on test set 2
// failing other sample cases
// I managed to get it to pass on the later samples
// however it still gets wa
// still wa on the 4th try
// problem is with the A queries as I can pass test set 1 easily
// still wa on test 2 :(

void solve() {
	ll l, n;
	cin >> l >> n;
	vector<pair<ll,char> > a(n);
	for (pair<ll,char>& i : a)
		cin >> i.f >> i.s;

	ll out = 0, pos = 0;
	char d = a[0].s;
	for (int i = 0; i < n; i++) {
		// Not a problem with this bit
		if (a[i].s == 'C') {
			if (!pos)
				d = a[i].s;
			out += max(0ll,(pos + a[i].f) / l + (d == a[i].s ? 0 : -1));
			if ((pos+a[i].f)/l)
				d = a[i].s;
			pos = (pos + a[i].f) % l;
		}
		// Something needs to be fixed here
		else {
			// if pos - a[i].f == 0 % l then it triggers
			// not a good idea to ceil it
			if (!pos)
				d = a[i].s;
			ll tmp = a[i].f/l;
			ll move = -(a[i].f%l);
			ll next = pos + move;
			// I didn't have <= and it led to quite a few wa
			if (next <= 0 && pos)
				tmp++;
			ll flag = tmp;
			//cout << "i: " << i << " tmp: " << tmp << "\n";
			if (tmp)
				tmp += d==a[i].s ? 0 : -1;
			if (flag)
				d = a[i].s;
			out += tmp;
			pos = (l + pos + move)%l;
		}
		//cout << "i: " << i << " pos: " << pos << " out: " << out << "\n";
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

