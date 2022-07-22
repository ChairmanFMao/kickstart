#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s, p;
    cin >> s >> p;
    
    int out = 0;
    int one = 0, two = 0;
    while (one < (int)s.size() && two < (int)p.size()) {
        if (s[one] == p[two]) {
            one++;
            two++;
        } else {
            two++;
            out++;
        }
    }

    if (one != (int)s.size())
        cout << "IMPOSSIBLE";
    else
        cout << p.size()-s.size();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}
