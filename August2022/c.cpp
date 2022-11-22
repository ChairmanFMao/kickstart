#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I think brute force can lead to O(n^2)
// binary search on each row/column maybe
// continues until it finds an unused tile
// maybe just sets for each of the rows and columns
// store cleverly in map
// Thinking of storing gaps in a vector for rows and columns
// This is pretty jank but it stores all of the gaps
// kinda like the solving linear probing in constant time

void solve() {
	int n, r, c, sr, sc;
	string s;
	cin >> n >> r >> c >> sr >> sc >> s;

	vector<set<int> > rg(r+1), cg(c+1);
	
	set<pair<int,int>> seen;
	seen.insert({sr,sc});
	int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

	if (sc >= 0 && !seen.count({sr+1,sc}))
		cg[sc].insert(sr+1);
	if (sc >= 0 && !seen.count({sr-1,sc}))
		cg[sc].insert(sr-1);
	if (sr >= 0 && !seen.count({sr,sc+1}))
		rg[sr].insert(sc+1);
	if (sr >= 0 && !seen.count({sr,sc-1})) {
		rg[sr].insert(sc-1);
	}
	for (int i = 0; i < n; i++) {
		int move = s[i] == 'N' ? 0 : s[i] == 'E' ? 1 : s[i] == 'S' ? 2 : 3;
		sr += dy[move];
		sc += dx[move];
		if (seen.count({sr,sc})) {
			if (move == 0) {
				int best = 0;
				vector<int> r;
				for (auto it = cg[sc].begin(); it != cg[sc].end(); it++)
					if (seen.count({*it,sc}))
						r.push_back(*it);
					else if (*it < sr)
						best = *it;
				sr = best;
				cg[sc].erase(best);
				for (int i : r)
					cg[sc].erase(i);
			}
			if (move == 1) {
				int best = INT_MAX;
				vector<int> r;
				for (auto it = rg[sr].begin(); it != rg[sr].end(); it++)
					if (seen.count({sr,*it}))
						r.push_back(*it);
					else if (*it > sc)
						best = min(best,*it);
				sc = best;
				rg[sr].erase(best);
				for (int i : r)
					rg[sr].erase(i);
			}
			if (move == 2) {
				int best = INT_MAX;
				vector<int> r;
				for (auto it = cg[sc].begin(); it != cg[sc].end(); it++)
					if (seen.count({*it,sc}))
						r.push_back(*it);
					else if (*it > sr)
						best = min(best,*it);
				sr = best;
				cg[sc].erase(best);
				for (int i : r)
					cg[sc].erase(i);
			}
			if (move == 3) {
				// This is not working properly, best is staying at zero
				int best = 0;
				vector<int> r;
				for (auto it = rg[sr].begin(); it != rg[sr].end(); it++)
					if (seen.count({sr,*it}))
						r.push_back(*it);
					else if (*it < sc)
						best = *it;
				sc = best;
				rg[sr].erase(best);
				for (int i : r)
					rg[sr].erase(i);
			}
		}
		
		if (sc >= 0 && !seen.count({sr+1,sc}))
			cg[sc].insert(sr+1);
		if (sc >= 0 && !seen.count({sr-1,sc}))
			cg[sc].insert(sr-1);
		if (sr >= 0 && !seen.count({sr,sc+1}))
			rg[sr].insert(sc+1);
		if (sr >= 0 && !seen.count({sr,sc-1}))
			rg[sr].insert(sc-1);

		seen.insert({sr,sc});
	}

	cout << sr << " " << sc << "\n";
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

