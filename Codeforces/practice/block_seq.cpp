#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
        int a = dp[i + 1];
        int s = v[i];
    
        if (i + s < n) {
            a = max(a, s + 1 + dp[i + s + 1]);
        }

        dp[i] = a;
    }

    cout << n - dp[0] << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}