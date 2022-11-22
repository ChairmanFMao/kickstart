#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// check if the stone is in the house

bool comp(pair<long double,int> a, pair<long double,int> b) {
	return a.f < b.f;
}

void solve() {
	long double rs, rh;
	cin >> rs >> rh;
	int n;
	cin >> n;
	vector<pair<long double, long double> > r(n);
	for (int i = 0; i < n; i++)
		cin >> r[i].f >> r[i].s;

	int m;
	cin >> m;
	vector<pair<long double, long double> > y(m);
	for (int i = 0; i < m; i++)
		cin >> y[i].f >> y[i].s;

	vector<pair<long double,int> > dist;
	for (int i = 0; i < n; i++)
		dist.push_back({sqrt(r[i].f*r[i].f+r[i].s*r[i].s)-rs,0});
	for (int i = 0; i < m; i++)
		dist.push_back({sqrt(y[i].f*y[i].f+y[i].s*y[i].s)-rs,1});

	if (sz(dist) == 0) {
		cout << "0 0\n";
		return;
	}

	vector<int> score = {0,0};
	sort(all(dist),comp);
	int ptr = 0, val = dist[0].s;
	while (ptr < sz(dist) && dist[ptr].s == val) {
		if (dist[ptr].f > rh)
			break;
		score[val]++;
		ptr++;
	}

	cout << score[0] << " " << score[1] << "\n";
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

