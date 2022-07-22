#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll test(string a) {
    ll out = 0;
    for (char i : a)
        out += i-48;
    return out % 9;
}

string compare(string best, string a) {
    if (best == "")
        return a;
    return best > a ? a : best;
}

void solve() {
    string n;
    cin >> n;
    string best = "";
    ll t = 9 - test(n);
    if (t == 9) {
        cout << n.substr(0,1) << "0" << n.substr(1);
        return;
    }

    best = compare(best,((char)(t+48)) + n);

    for (int i = 1; i <= (int)n.size(); i++) {
        if (i == (int)n.size()) {
            best = compare(best,(n + (char)(t+48)));
            break;
        } if (n[i]-48 > t) {
            string current = n.substr(0,i) + (char)(t+48) + n.substr(i);
            best = compare(best,current);
            break;
        }
    }

    cout << best;
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
