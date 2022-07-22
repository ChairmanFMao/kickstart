#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// At most 100 characters in each expression
// So methods O(n^2) and O(n^3) are possible

void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	set<char> vowels;
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');

	vector<int> vPos;
	for (int i = 0; i < n; i++)
		if (vowels.count(s[i]))
			vPos.push_back(i);

	// Starting position
	for (int i = 0; i < n; i++) {
		// Length of the starting word
		for (int j = 2; j+i <= n; j++) {
			// Validates the number of vowels in the first word
			int vc = 0;
			for (int k = i; k < i+j; k++)
				vc += vowels.count(s[k]);
			// Skips it if its invalid
			if (vc < 2)
				continue;
			
			// Finding the ending word
			int flag = 0;
			for (int k = i+j; k+j <= n; k++) {
				if (s.substr(i,j) == s.substr(k,j) && flag) {
					cout << "Spell!\n";
					return;
				}
				flag |= vowels.count(s[k]);
			}
		}
	}

	cout << "Nothing.\n";
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
