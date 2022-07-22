#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Radiate out from every post office and place the office
// on the square with the maximum value?
// Need to do in less than O((rc)^2)
// Min values can be calculated for the whole grid in O(rc) with bfs
//
// I epicly did it!!!!!!!!!
// I did all of the coding practice session!!!!!

struct Node {
	int r;
	int c;
	int d;
};

bool comp(Node a, Node b) {
	return a.d > b.d;
}

void solve() {
	int r, c;
	cin >> r >> c;
	vector<vector<bool> > grid(r, vector<bool>(c));
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
			grid[i][j] = s[j] & 1;
	}

	vector<vector<bool> > seen(r, vector<bool>(c,0));
	vector<vector<int> > near(r, vector<int>(c,INT_MAX));
	queue<Node> q;
	Node n;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (grid[i][j]) {
				seen[i][j] = 1;
				near[i][j] = 0;
				n.r = i; n.c = j; n.d = 0;
				q.push(n);
			}

	while (!q.empty()) {
		Node current = q.front();
		q.pop();
		int i = current.r, j = current.c, d = current.d;
		if (i-1 >= 0 && !seen[i-1][j]) {
			n.r = i-1; n.c = j; n.d = d+1;
			seen[n.r][n.c] = 1;
			near[n.r][n.c] = n.d;
			q.push(n);
		} if (i+1 < r && !seen[i+1][j]) {
			n.r = i+1; n.c = j; n.d = d+1;
			seen[n.r][n.c] = 1;
			near[n.r][n.c] = n.d;
			q.push(n);
		} if (j-1 >= 0 && !seen[i][j-1]) {
			n.r = i; n.c = j-1; n.d = d+1;
			seen[n.r][n.c] = 1;
			near[n.r][n.c] = n.d;
			q.push(n);
		} if (j+1 < c && !seen[i][j+1]) {
			n.r = i; n.c = j+1; n.d = d+1;
			seen[n.r][n.c] = 1;
			near[n.r][n.c] = n.d;
			q.push(n);
		}
	}

	vector<Node> nodes;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			n.r = i; n.c = j; n.d = near[i][j];
			nodes.push_back(n);
		}

	// Sorts all the nodes depending on their distance values
	sort(all(nodes),comp);

	int out = nodes[0].d;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int best = 0, ptr = 0, next = 0;
			while (ptr < sz(nodes)) {
				next = abs(nodes[ptr].r-i) + abs(nodes[ptr].c-j); 
				if (next < nodes[ptr].d) {
					best = max(best, next);
				} else {
					best = max(best, nodes[ptr].d);
					break;
				}
				ptr++;
			}
			out = min(out, best);
		}
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
