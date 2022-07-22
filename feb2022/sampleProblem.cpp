
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int c) {
    int n, m;
    cin >> n >> m;
    int total = 0;
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        total += a;
    }

    cout << "Case #" << c << ": " << total%m << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve(i);
}
