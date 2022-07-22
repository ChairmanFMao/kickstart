#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Recursive backtracking maybe?
// I should at least be able to get first test I think
// Palindromes of length 5 or higher ;-;, need to do more checking for 6 long

string s, current;
int n;
vector<int> q;

bool palindrome(string a) {
    for (int i = 0; i < (int)a.size()/2; i++) {
        if (a[i] == '?' || a[a.size()-i-1] == '?')
            return 0;
        if (a[i] != a[a.size()-i-1])
            return 0;
    }
    return 1;
}

bool valid(int index) {
    bool out = 1;
    for (int i = index-4; i <= index; i++) {
        if (i >= 0 && n - i >= 5)
            out &= !palindrome(current.substr(i,5));
    }
    for (int i = index-5; i <= index; i++)
        if (i >= 0 && n - i >= 6)
            out &= !palindrome(current.substr(i,6));
    return out;
}

bool recur(int depth) {
    if (depth == (int)q.size()) {
        // cout << current << "\n";
        return 1;
    }

    bool out = 0;
    current[q[depth]] = '0';
    if (valid(q[depth]))
        out |= recur(depth+1);
    
    if (out)
        return out;

    current[q[depth]] = '1';
    if (valid(q[depth]))
        out |= recur(depth+1);
    
    current[q[depth]] = '?';
    return out;
}

void solve() {
    cin >> n >> s;
    q.clear();
    for (int i = 0; i < n; i++)
        if (s[i] == '?')
            q.push_back(i);
    
    bool out = 0;
    for (int i = 0; i <= n-5; i++)
        out |= palindrome(s.substr(i,5));
    for (int i = 0; i <= n-6; i++)
        out |= palindrome(s.substr(i,6));

    current = s;
    cout << ((!out && recur(0)) ? "" : "IM") << "POSSIBLE";
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
