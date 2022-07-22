#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Maybe look at prime factors, idk
// Every number with a zero works
// Can't simply generate a set of all the numbers, it will take up too much memory and time
// Won't occur if sum of digits is even and product is odd
// Can do 3 and 9 quite easily
// Won't be possible to iterate for bigger numbers
// At least 18 occurs every 100 due to the zeros

// Unsure how to do this efficiently

// Third in the UK, 659 overall!

// First dimension is for lengths
// Second dimension is for all the combinations
// Third dimension is for combinations - last number is repeats
vector<vector<vector<int> > >combinations(13);
vector<int> current;

void combos(int last, ll product, ll sum, int target, int size, int repeats) {
    if (target == size) {
        if (sum) {
            if (!(product%sum)) {
                current.push_back(repeats);
                combinations[size].push_back(current);
                current.pop_back();
            }
        }
        return;
    }
    for (int i = last; i >= 0; i--) {
        if (size == 0 && i == 0)
            continue;
        current.push_back(i);
        combos(i,i?product*i:product,sum+i, target, size+1, repeats+(i==last));
        current.pop_back();
    }
}

// n is the length, cap is the highest number possible
ll counting(ll n, ll cap) {
    ll out = 0;
    vector<int> digits;
    while (cap) {
        digits.push_back(cap%10);
        cap /= 10;
    }
    reverse(digits.begin(),digits.end());
    for (int i = 0; i < (int)combinations[n].size(); i++) {
        cout << "";
    }
    return out;
}

ll solve2(ll n) {
    int length = to_string(n).size();
    cout << "target size: " << length << "\n";
    for (int i = 1; i <= length; i++)
        combos(9,1,0,i,0,0);
    return 0;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << solve2(b) << "\n";
    ll totalSize = 0;
    for (int i = 1; i <= (int)to_string(b).size(); i++)
        totalSize += combinations[i].size();
    cout << "length: " << totalSize << "\n";
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
    }
}
