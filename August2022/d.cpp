#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think you can do this with a segment tree and range queries
// Should lead to O(n log n) time complexity I think
// This was actually such a nice problem to solve

struct Segtree {
	vector<int> tr;
	int n;
	Segtree(vector<int> v) {
		n = sz(v);
		tr.resize(n+n);
		for (int i = 0; i < n; i++)
			tr[n+i] = v[i];
		for (int i = n-1; i > 0; i--)
			tr[i] = tr[i+i] + tr[i+i+1];
	}
 
	int query(int l, int r) {
		int out = 0;
		for (l += n, r += n; l <= r; l>>=1, r>>=1) {
			if (l&1)
				out += tr[l++];
			if (!(r&1))
				out += tr[r--];
		}
		return out;
	}
 
	void update(int pos, int val) {
		tr[n+pos] += val;
		for (int i = (n+pos)>>1; i > 0; i>>=1)
			tr[i] = tr[i+i] + tr[i+i+1];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> range(5002,0);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; b++;
		range[a]++;
		range[b]--;
	}

	Segtree seg(range);

	int p;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int c; cin >> c;
		cout << seg.query(0,c) << " ";
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

