
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[500][500], b[500][500], r[500], c[500], n;

// Something about dsu - disjoint set union

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++)
        cin >> r[i];
    
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll out = 0;
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
