#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Seems like a dp problem
// plant the ones that give the most profit and will grow to full
// before the end of the season, priority queue maybe?
// sort by most profit and then longest to grow
// linear time over days is not possible
// need linear time over the number of seeds
// just binary search for the next last planting time
// currently estimating too high
// problem is that there are ones of lower value that need to go
// first as they would grow at the very end
// put them so that they cover a range?
// then do the ones that are most valuable first
// somehow need to arrange the blocks in the best way possible
// put the block as far back as possible and insert the next where
// ever is possible
// need to also allow the blocks to fuse into each other
// have a stack of positions where it could go?
// current approach doesn't work
// search for first open position after the planting time
// can't easily check if a time is used
// need something linear over n otherwise it won't pass the third
// test case set
// current solution should be roughly O(d * smth?)
// got points for the second test case for this problem
// unsure entirely how to solve the third with linear time over n
// maybe just keep same approach and change the vector to a map?
// still get mle due to the larger numbers

struct Seed {
	ll q, l, v;
};

bool comp(Seed a, Seed b) {
	return a.v == b.v ? a.l < b.l : a.v > b.v;
}

void solve() {
	ll d, n, x;
	cin >> d >> n >> x;
	vector<Seed> seeds(n);
	for (Seed& i : seeds)
		cin >> i.q >> i.l >> i.v;

	sort(all(seeds),comp);
	map<ll,ll> days;
	set<ll> free;
	ll out = 0;
	for (ll i = 0; i < n; i++) {
		ll current = seeds[i].l, total = seeds[i].q;
		while (current < d && total) {
			if (days[current] == x) {
				auto temp = free.upper_bound(current);
				if (temp == free.end())
					break;
				current = *temp;
				free.erase(current);
			}
			ll val = min(total,x-days[current]);
			total -= val;
			out += val * seeds[i].v;
			days[current] += val;
			if (!total) {
				if (days[current] == x && current < d-1)
					free.insert(current+1);
				else if (days[current] < x)
					free.insert(current);
			}
			current++;
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

