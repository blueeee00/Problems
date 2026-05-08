#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int l;
    string x;
    cin >> l >> x;

    int a = 0;
    int b = 0;

    for (int i = 0; i < l; i++) {
        if (x[i] == '(') {
            a++;
        } else {
            b++;
        }
    }

    if (a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}