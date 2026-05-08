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
    int an, bn;
    cin >> an >> bn;

    vector<int> as(an);
    vector<int> bs(bn);

    for (auto &it: as) cin >> it;
    for (auto &it: bs) cin >> it;

    vector<vector<int>> dp(an + 1, vector<int>(bn + 1, 0));
    for (int i = 1; i <= an; i++) {
        for (int j = 1; j <= bn; j++) {
            if (as[i - 1] == bs[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[an][bn] << endl;
    
    vector<int> lcs;
    int i = an, j = bn;
    while (i > 0 && j > 0) {
        if (as[i - 1] == bs[j - 1]) {
            lcs.push_back(as[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    for (int x: lcs) cout << x << space;
}

signed main() {
    fastIO;
    solve();
    return 0;
}