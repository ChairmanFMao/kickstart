
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// I think that you need to use a fenwick tree with a binary search
// I think the complexity is O(n logn logn) but, I'm not entirely sure

const int mxN = 1e5;
vector<int> fenwick(mxN+1);

// Keeps going upwards in the fenwick tree to update a value by one
void update(int index) {
    while (index <= mxN) {
        fenwick[index]++;
        index += index & (-index);
    }
}

// Gets the sum of the first index elements
int total(int index) {
    int out = 0;
    while (index > 0) {
        out += fenwick[index];
        index -= index & (-index);
    }
    return out;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= mxN; i++)
        fenwick[i] = 0;
    
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        update(a);
        int lower = 0, upper = mxN, mid = 0, best = 0;
        while (lower <= upper) {
            mid = (lower+upper) >> 1;
            // This gets the sum of values that are greater or equal to mid
            if (total(mxN) - total(mid-1) >= mid) {
                best = mid;
                lower = mid+1;
            } else {
                upper = mid-1;
            }
        }
        cout << best << " ";
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
