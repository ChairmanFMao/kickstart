
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int score = 0;
    for (int i = 0; i < (int)s.size()/2; i++) {
        if (s[i] != s[s.size()-i-1])
            score++;
    }

    cout << abs(k-score);
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
