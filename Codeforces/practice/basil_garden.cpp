#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it: v) cin >> it;

    vector<int> dp(n);

    int ans = v[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans + 1, v[i]);
    }

    cout << ans;
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