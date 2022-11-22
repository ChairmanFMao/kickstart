#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Ada can have negative coins
// m <= 20, potentially just a brute force might work
// has to deliver the pizza as well, it may not be optimum to deliver pizza
// due to the tolls being dependent on her current coins
// for the first test as p = 0, we are just attempting to get as much money
// as possible through the tolls
// for the first test then the minimum coins she can have is 0
// kd always positive so maybe a dijkstra's like thing?
// We are also going to be using a 1 indexed grid for ease
// Pretty pleased that I got this to pass test case 1 at least
// Maybe just have another dimension for customers seen for test case 2
// this dimension would be of size 2^10
// O(n * n * m * 2^10) ~= 200 * 2^10
// This may potentially work
// Currently getting a value below on one of the test inputs

struct Customer {
	ll x, y, price;
};

struct State {
	ll x, y, time, money, seen;
};

ll operation(pair<char,ll> t, ll number) {
	if (t.f == '-')
		return number - t.s;
	if (t.f == '+')
		return number + t.s;
	if (t.f == '*')
		return number * t.s;
	if (t.f == '/')
		return floor(number / ((long double) t.s));
	return 0;
}

void solve() {
	ll n, p, m, ar, ac;
	cin >> n >> p >> m >> ar >> ac;

	vector<pair<char,ll>> op(4);
	for (ll i = 0; i < 4; i++)
		cin >> op[i].f >> op[i].s;

	vector<Customer> customers;
	Customer customer;
	for (ll i = 0; i < p; i++) {
		cin >> customer.y >> customer.x >> customer.price;
		customers.push_back(customer);
	}

	// First two dimensions are for the actual grid
	// Third dimension is for the time
	// Fourth dimension is for the customers seen
	// Actual value is for the money
	vector<vector<vector<vector<ll>>>> grid(n+1,vector<vector<vector<ll>>>(n+1,vector<vector<ll>>(m+1,vector<ll>(1<<p,LONG_LONG_MIN))));

	// Potentially optimise with a set for whats currently in the queue
	grid[ac][ar][0][0] = 0;
	queue<State> q;
	State st;
	st.x = ac; st.y = ar; st.time = 0; st.money = 0; st.seen = 0;
	q.push(st);

	while (sz(q)) {
		st = q.front();
		q.pop();

		if (st.time >= m)
			continue;
		ll start = grid[st.x][st.y][st.time][st.seen], value;
		st.time++;
		if (st.x > 1) {
			st.x--;
			value = operation(op[2],start);
			if (value > grid[st.x][st.y][st.time][st.seen]) {
				grid[st.x][st.y][st.time][st.seen] = value;
				q.push(st);
				for (ll i = 0; i < p; i++)
					if (customers[i].x == st.x && customers[i].y == st.y && !(st.seen&(1<<i))) {
						st.seen ^= (1<<i);
						if (value+customers[i].price > grid[st.x][st.y][st.time][st.seen]) {
							grid[st.x][st.y][st.time][st.seen] = value+customers[i].price;
							q.push(st);
						}
						st.seen ^= (1<<i);
					}
			}
			st.x++;
		} if (st.x < n) {
			st.x++;
			value = operation(op[1],start);
			if (value > grid[st.x][st.y][st.time][st.seen]) {
				grid[st.x][st.y][st.time][st.seen] = value;
				q.push(st);
				for (ll i = 0; i < p; i++)
					if (customers[i].x == st.x && customers[i].y == st.y && !(st.seen&(1<<i))) {
						st.seen ^= (1<<i);
						if (value+customers[i].price > grid[st.x][st.y][st.time][st.seen]) {
							grid[st.x][st.y][st.time][st.seen] = value+customers[i].price;
							q.push(st);
						}
						st.seen ^= (1<<i);
					}
			}
			st.x--;
		} if (st.y > 1) {
			st.y--;
			value = operation(op[0],start);
			if (value > grid[st.x][st.y][st.time][st.seen]) {
				grid[st.x][st.y][st.time][st.seen] = value;
				q.push(st);
				for (ll i = 0; i < p; i++)
					if (customers[i].x == st.x && customers[i].y == st.y && !(st.seen&(1<<i))) {
						st.seen ^= (1<<i);
						if (value+customers[i].price > grid[st.x][st.y][st.time][st.seen]) {
							grid[st.x][st.y][st.time][st.seen] = value+customers[i].price;
							q.push(st);
						}
						st.seen ^= (1<<i);
					}
			}
			st.y++;
		} if (st.y < n) {
			st.y++;
			value = operation(op[3],start);
			if (value > grid[st.x][st.y][st.time][st.seen]) {
				grid[st.x][st.y][st.time][st.seen] = value;
				q.push(st);
				for (ll i = 0; i < p; i++)
					if (customers[i].x == st.x && customers[i].y == st.y && !(st.seen&(1<<i))) {
						st.seen ^= (1<<i);
						if (value+customers[i].price > grid[st.x][st.y][st.time][st.seen]) {
							grid[st.x][st.y][st.time][st.seen] = value+customers[i].price;
							q.push(st);
						}
						st.seen ^= (1<<i);
					}
			}
			st.y--;
		}
	}

	ll out = LONG_LONG_MIN;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			for (ll k = 0; k <= m; k++)
				out = max(out,grid[i][j][k][(1<<p)-1]);

	if (out == LONG_LONG_MIN)
		cout << "IMPOSSIBLE\n";
	else
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

