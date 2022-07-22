#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I think I can get the first case here
// Strongly connected components, I think
// Need to look for groups that can be flipped on or off
// I have the sizes of the components and what totals they can make
// However, idk what to do with it really
// Need to find which components point at each other
// We can make another graph with the components
// Need representatives for the components and edges for each component
// should be calculated for another graph
//
// Getting wa on test 12 of test set 1
// The output is 1140 when it should be 2970
// for test set 2, there are quite a lot of off by 1 errors

const int mxN = 1e5;
ll n, m, k, counter, out = 0, currentComponent = 0;
vector<vector<int> > adj(mxN), revAdj(mxN), strong(mxN), strongAdj(mxN);
ll ending[mxN], seen[mxN], value[mxN];
vector<set<int> > strongSets(mxN), strongAdjSets(mxN);
map<int,int> setMap;
vector<int> strongSeen(mxN);
ifstream in;

// for sorting nodes in kosaraju's
bool compare(pair<ll,ll> a, pair<ll,ll> b) {
	return a.first > b.first;
}

// for first dfs in kosaraju's
void dfs(int node) {
	if (seen[node])
		return;
	seen[node] = 1;
	for (int i : adj[node])
		dfs(i);
	counter++;
	ending[node] = counter;
}

// for second dfs in kosaraju's
void dfs2(int node) {
	if (seen[node])
		return;
	strong[currentComponent].push_back(node);
	strongSets[currentComponent].insert(node);
	setMap[node] = currentComponent;
	seen[node] = 1;
	for (int i : revAdj[node])
		dfs2(i);
}

// for final innocent calcuation
ll dfs3(int component) {
	if (strongSeen[component])
		return value[component];
	strongSeen[component] = 1;
	value[component] += sz(strong[component]);
	for (int i : strongAdj[component])
		value[component] += dfs3(i);
	return value[component];
}

// main function
void solve() {
	in >> n >> m >> k;

	// clears all of the global variables
	currentComponent = 0;
	out = 0;
	setMap.clear();
	for (int i = 0; i < n; i++) {
		strongAdj[i].clear();
		strong[i].clear();
		strongSets[i].clear();
		strongAdjSets[i].clear();
		strongSeen[i] = 0;
		value[i] = 0;
		adj[i].clear();
		revAdj[i].clear();
		ending[i] = 0;
		seen[i] = 0;
	}

	// Takes the input edges in the graph
	for (int i = 0; i < m; i++) {
		int a, b;
		in >> a >> b;
		a--; b--;
		adj[b].push_back(a);
		revAdj[a].push_back(b);
	}

	// does first dfs for kosaraju's
	counter = 0;
	for (int i = 0; i < n; i++)
		if (!seen[i])
			dfs(i);

	// gets all of the nodes values for kosaraju's
	vector<pair<ll,ll> > nodes;
	for (int i = 0; i < n; i++)
		nodes.push_back({ending[i],i});

	// sorts nodes from greatest value to smallest of ending processing
	sort(all(nodes),compare);
	for (int i = 0; i < n; i++)
		seen[i] = 0;

	// second dfs for kosaraju's
	for (int i = 0; i < n; i++)
		if (!seen[nodes[i].second]) {
			dfs2(nodes[i].second);
			currentComponent++;
		}

	// getting the edges between the strongly connected components
	for (int i = 0; i < currentComponent; i++)
		for (int j : strong[i])
			for (int l : adj[j])
				if (!strongSets[i].count(l))
					strongAdjSets[i].insert(setMap[l]);

	// Converts the sets to vectors
	for (int i = 0; i < currentComponent; i++) {
		vector<int> tmp(all(strongAdjSets[i]));
		strongAdj[i] = tmp;
	}

	// final dfs for the last calculation
	for (int i = 0; i < currentComponent; i++)
		dfs3(i);

	// Gets all of the components that are certified innocent
	for (int i = 0; i < currentComponent; i++)
		if (value[i] > k)
			out += sz(strong[i]);
	
	cout << out << "\n";
}

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	in.open("C:/Users/Freddie/Downloads/test_data/test_set_1/ts1_input.txt");
	auto start = high_resolution_clock::now();
	int t;
	in >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop-start);
	cout << "time: " << duration.count() << "\n";
}

