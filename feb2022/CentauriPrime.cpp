
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// They are really sticklers for detail, I need to be more careful when submitting.

void solve(int c) {
    string s;
    cin >> s;
    set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    
    cout << "Case #" << c << ": " << s << " is ruled by " << (s[s.size()-1] == 'y' || s[s.size()-1] == 'Y' ? "nobody" : vowels.count(s[s.size()-1]) ? "Alice" : "Bob") << ".\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve(i);
} 
