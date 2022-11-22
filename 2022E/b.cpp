#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think that this is possible in linear time with a traversal kinda
// Rj <= 2 * Ri
// Need to make it so that a student can't be a mentor of themselves
// This is a simple binary search one acc

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.f < b.f;
}

void solve() {
	int n;
	cin >> n;
	vector<int> r(n);
	for (int& i : r)
		cin >> i;

	vector<pair<int,int>> b;
	for (int i = 0; i < n; i++)
		b.push_back({r[i],i});
	sort(all(b),comp);

	for (int i = 0; i < n; i++) {
		int low = 0, high = n, mid = 0, f = 0, a;
		while (1) {
			if (f)
				break;
			if (low == high-1)
				f = 1;

			mid = (low+high) / 2;
			if (b[mid].f <= r[i] * 2) {
				low = mid;
				a = 1;
			} else
				high = mid;
		}
		if (b[mid].s == i)
			mid--;
		cout << (a && mid >= 0 ? b[mid].f : -1) << " ";
	}

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

