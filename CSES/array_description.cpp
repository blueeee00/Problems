#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define space ' '
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define ppb pop_back

#define MOD1 1000000007
#define MOD2 998244353
#define INF LLONG_MAX

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto &it: arr) cin >> it;

    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    forn(i, n) {
        if (i == 0) {
            if (arr[i] == 0) {
                for (int j = 1; j <= m; j++) {
                    dp[0][j] = 1;
                }
            } else {
                dp[0][arr[i]] = 1;
            }
        } else {
            if (arr[i] == 0) {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD1;
                }
            } else {
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % MOD1;
    }

    cout << ans;
}

signed main() {
    fastIO;
    solve();
    return 0;
}

// 2 0 0
// 0 3 