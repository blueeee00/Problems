#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
    }

    vector<int> v2 = v;
    reverse(v2.begin(), v2.end());

    int best = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < (2 * n) - i; j++) {
            if (v[j] != v2[i + j]) {
                // cout << i << '\n';
                break;
            } else {
                // cout << v[j] << '\n';
                current++;
            }
        }

        // cout << '\n';
        best = max(best, current);
    }

    cout << best << '\n';
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

// 0 1 2 1 0 2
// 2 0 1 2 1 0

// 0 1 0 1
// 1 0 1 0

// 