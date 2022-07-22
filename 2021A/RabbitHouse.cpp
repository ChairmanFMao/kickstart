
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int grid[300][300], r, c;

bool high(int i, int j) {
    if (i > 0)
        if (grid[i-1][j] < grid[i][j])
            return 1;
    if (j > 0)
        if (grid[i][j-1] < grid[i][j])
            return 1;
    if (j < c-1)
        if (grid[i][j+1] < grid[i][j])
            return 1;
    if (i < r-1)
        if (grid[i+1][j] < grid[i][j])
            return 1;
    return 0;
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];

    queue<pair<int,int>> process;
    ll ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (high(i,j))
                process.push({i,j});
        }
    }

    while (process.size()) {
        pair<int,int> current = process.front();
        int a = current.first, b = current.second;
        process.pop();
        if (a > 0)
            if (grid[a][b] - grid[a-1][b] > 1) {
                ans += grid[a][b] - grid[a-1][b] - 1;
                grid[a-1][b] += grid[a][b] - grid[a-1][b] - 1;
                process.push({a-1,b});
            }
        if (b > 0)
            if (grid[a][b] - grid[a][b-1] > 1) {
                ans += grid[a][b] - grid[a][b-1] - 1;
                grid[a][b-1] += grid[a][b] - grid[a][b-1] - 1;
                process.push({a,b-1});
            }
        if (b < c-1)
            if (grid[a][b] - grid[a][b+1] > 1) {
                ans += grid[a][b] - grid[a][b+1] - 1;
                grid[a][b+1] += grid[a][b] - grid[a][b+1] - 1;
                process.push({a,b+1});
            }
        if (a < r-1)
            if (grid[a][b] - grid[a+1][b] > 1) {
                ans += grid[a][b] - grid[a+1][b] - 1;
                grid[a+1][b] += grid[a][b] - grid[a+1][b] - 1;
                process.push({a+1,b});
            }
    }

    cout << ans;
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
