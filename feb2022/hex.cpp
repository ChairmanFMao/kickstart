
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// It is impossible if there is more than 1 of red or blue
// There are more than just straight paths, a silly oversight
// I think that you need to do a dijkstra's potentially?

void solve() {
    int n, r = 0, b = 0;
    cin >> n;
    // Zero represents empty, 1 is Blue, 2 is Red
    vector<vector<int>> grid(n, vector<int> (n, 0));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] == '.' ? 0 : s[j] == 'B' ? 1 : 2;
            if (s[j] == 'B')
                b++;
            else if (s[j] == 'R')
                r++;
        }
    }
    
    // Checks for impossible
    if (abs(r-b) > 1) {
        cout << "Impossible";
        return;
    }
    
    int redw = 0, bluew = 0;
    // Checks if red has won
    for (int i = 0; i < n; i++) {
        bool good = 1;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] != 2) {
                good = 0;
                break;
            }
        }
        if (good) {
            redw++;
        }
    }

    // Checks if blue has won
    for (int i = 0; i < n; i++) {
        bool good = 1;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 1) {
                good = 0;
                break;
            }
        }
        if (good) {
            bluew++;
        }
    }

    if (redw > 1 || bluew > 1) {
        cout << "Impossible";
    } else {
        cout << (redw == 1 ? "Red" : bluew == 1 ? "Blue" : "Nobody") << " wins";
    }
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
