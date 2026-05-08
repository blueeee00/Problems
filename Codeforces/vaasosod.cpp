#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        for (int p = 1; p <= n; p *= 10) {
            int high = n / (p * 10);
            int cur = (n / p) % 10;
            int low = n % p;

            ans += high * 45 * p;
            ans += (cur * (cur - 1) / 2) * p;
            ans += cur * (low + 1);
        }

        cout << ans << '\n';
    }
}