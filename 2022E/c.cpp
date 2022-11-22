#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Find shortest palindrome to append to p
// for it to be a palindrome
// Very easy method in O(n^2) by just adding letters from the back until its built up
// thinking about searching for pivot points or smth
// method I was thinking of wasn't better than O(n^2 / 4)
// I think a recursive breakdown might be good
// This works in O(n sqrt n)
// Somehow getting wa on test 2
//
// Very happy that I finally managed to solve this after a while

bool pal(string s) {
	for (int i = 0; i < sz(s)/2; i++)
		if (s[i] != s[sz(s)-i-1])
			return 0;
	return 1;
}

int n, best = INT_MAX;
string p;

void solve() {
	cin >> n >> p;
	best = n;

	set<char> se;
	for (char c : p)
		se.insert(c);
	
	if (sz(se) == 1) {
		cout << p[0] << "\n";
		return;
	}

	for (int i = 2; i*i <= n; i++) {
		if (n % i)
			continue;
		string temp = p + p.substr(0,n/i);
		if (pal(temp) && pal(p.substr(0,n/i)))
			best = min(best,n/i);
		temp = p + p.substr(0,i);
		if (pal(temp) && pal(p.substr(0,i)))
			best = min(best,i);
	}

	cout << p.substr(0,best) << "\n";
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

