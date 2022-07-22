#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// All the ants have the same constant speed
// Can't simulate it if I want all the points
// Need to mathematically calculate where they will collide
// Maybe just keep calculating time until next collision and doing that
// interval, would work with larger cases I think
// I also made the intervals half a second to make it easier
// Works for cases 1 and 2 but, still times out on 3
// Maybe I need to cache the collision times and dynamically update them
// There just needs to be a small optimisation to get the last case

struct Ant {
	ll move;
	ll location;
	ll value;
};

bool cmp(Ant f, Ant s) {
	return f.location < s.location;
}

bool cmp2(pair<ll,ll> f, pair<ll,ll> s) {
	return f.first == s.first ? f.second < s.second : f.first < s.first;
}

void solve() {
	ll n, l;
	cin >> n >> l;
	vector<Ant> ants;
	for (int i = 0; i < n; i++) {
		Ant ant;
		cin >> ant.location >> ant.move;
		ant.location *= 2;
		ant.value = i+1;
		if (!ant.move)
			ant.move = -1;
		ants.push_back(ant);
	}

	sort(all(ants),cmp);

	int number = n;
	int start = 0, end = n, moves = 0;
	vector<pair<ll,ll> > out;
	// We set up the intervals priority queue
	priority_queue<pair<ll,ll> > intervals;
	for (int i = start; i < end-1; i++)
		if (ants[i].move == 1 && ants[i+1].move == -1)
			intervals.push({(ants[i+1].location - ants[i].location) / 2,i});

	while (number) {
		// Removes starting ones
		for (int i = start; i < end; i++) {
			if (ants[i].move == -1) {
				out.push_back({ants[i].location+moves*ants[i].move,ants[i].value});
				start++;
				number--;
			} else
				break;
		}

		// Removes ending ones
		for (int i = end-1; i >= start; i--) {
			if (ants[i].move == 1) {
				out.push_back({2*l-ants[i].location+moves*ants[i].move,ants[i].value});
				end--;
				number--;
			} else
				break;
		}
		
		if (!number)
			break;
		// Gets the next interval
		ll current = intervals.top().first;
		vector<ll> change;
		change.clear();
		while (intervals.top().first == current && !intervals.empty()) {
			change.push_back(intervals.top().second);
			intervals.pop();
		}

		moves += current;

		for (ll i : change) {
			ants[i].location += moves * ants[i].move;
			ants[i].move *= -1;
			ants[i].location -= moves * ants[i].move;

			if (i != start)
				if (ants[i].move == -1 && ants[i-1].move == 1)
					intervals.push({(ants[i].location+moves*ants[i].move - ants[i-1].location-moves*ants[i-1].move)/2, i-1});

			ants[i+1].location += moves * ants[i+1].move;
			ants[i+1].move *= -1;
			ants[i+1].location -= moves * ants[i+1].move;

			if (i != end)
				if (ants[i].move == 1 && ants[i+1].move == -1)
					intervals.push({(ants[i+1].location+moves*ants[i+1].move - ants[i].location-moves*ants[i].move)/2, i+1});

		}
	}

	sort(all(out),cmp2);
	for (int i = 0; i < n; i++)
		cout << out[i].second << " ";
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

