#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
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
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()

#define MOD1 1000000007
#define MOD2 998244353
#define INF LLONG_MAX

#define vin(v) for (auto &x : v) cin >> x
#define out(x) cout << x << endl
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);

    int sum = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        sum += v[i];
        dp[i][i] = v[i];
    }

    rep(len, 2, n + 1) {
        rep(i, 0, n - len + 1) {
            int j = i + len - 1;
            dp[i][j] = max(v[j] - dp[i][j - 1], v[i] - dp[i + 1][j]);
        }
    }

    out((sum + dp[0][n - 1]) / 2);
}

signed main() {
    fastIO;
    solve();
    return 0;
}

// 4 5 1 3
// dp[l][r] = max(v[r] - dp[l][r - 1], v[l] - dp[l + 1][r])