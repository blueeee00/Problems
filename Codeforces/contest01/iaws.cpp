#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int low = 1e16;
    int idx = n - 1;
    while (v[idx] < low && idx > 0) {
        low = v[idx];
        idx--;
    }

    if (low == 1e16) {
        cout << 0 << '\n';
        return;
    }

    low--;
    int sum = 0;
    for (int i = idx; i >= 0; i--) {
        sum += max((int) 0, v[i] - low);
    }

    cout << sum << '\n';
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
