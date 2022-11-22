#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

struct Fabric {
	string c;
	int d, u, id;
};

bool comp(Fabric a, Fabric b) {
	return a.c == b.c ? a.u < b.u : a.c < b.c;
}

bool comp2(Fabric a, Fabric b) {
	return a.d == b.d ? a.u < b.u : a.d < b.d;
}

void solve() {
	int n;
	cin >> n;
	vector<Fabric> a(n), b(n);
	for (int i = 0; i < n; i++) {
		string c;
		int d, u; cin >> c >> d >> u;
		a[i].c = c; a[i].d = d; a[i].u = u; a[i].id = i;
		b[i].c = c; b[i].d = d; b[i].u = u; b[i].id = i;
	}

	sort(all(a),comp);
	sort(all(b),comp2);

	int out = 0;
	for (int i = 0; i < n; i++)
		if (a[i].id == b[i].id)
			out++;

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

