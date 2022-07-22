
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int grid[1000][1000];
// down, up, right, left
int cnt[1000][1000][4];

int calc(int a, int b) {
    int out = 0;
    out += min(a,b/2);
    out += min(b,a/2);
    if (a > 1)
        out--;
    if (b > 1)
        out--;
    
    return out;
}

void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    
    // down
    int mid = 0;
    for (int i = 0; i < c; i++) {
        mid = 0;
        for (int j = r-1; ~j; j--) {
            if (!grid[j][i])
                mid = 0;
            mid += grid[j][i];
            cnt[j][i][0] = mid;
        }
    }
    
    // up
    for (int i = 0; i < c; i++) {
        mid = 0;
        for (int j = 0; j < r; j++) {
            if (!grid[j][i])
                mid = 0;
            mid += grid[j][i];
            cnt[j][i][1] = mid;
        }
     }

    // right
    for (int j = 0; j < r; j++) {
        mid = 0;
        for (int i = c-1; ~i; i--) {
            if (!grid[j][i])
                mid = 0;
            mid += grid[j][i];
            cnt[j][i][2] = mid;
        }
    }

    // left
    for (int j = 0; j < r; j++) {
        mid = 0;
        for (int i = 0; i < c; i++) {
            if (!grid[j][i])
                mid = 0;
            mid += grid[j][i];
            cnt[j][i][3] = mid;
        }
    }

    ll out = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (grid[i][j]) {
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        out += calc(cnt[i][j][k], cnt[i][j][l+2]);
            }
        }
    
    cout << out;
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
