#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	string s;
	cin >> n >> s;

	set<char> special;
	special.insert('#');
	special.insert('@');
	special.insert('*');
	special.insert('&');

	bool specialb = 0, upper = 0, lower = 0, digit = 0;
	for (char c : s) {
		if (special.count(c))
			specialb = 1;
		if (isupper(c))
			upper = 1;
		if (islower(c))
			lower = 1;
		if (isdigit(c))
			digit = 1;
	}

	if (!specialb)
		s += '#';
	if (!upper)
		s += 'A';
	if (!lower)
		s += 'a';
	if (!digit)
		s += '0';

	while (sz(s) < 7)
		s += 'a';
	
	cout << s << "\n";
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

