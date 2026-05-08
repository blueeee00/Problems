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
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    vin(v);

    vector<pair<int, int>> dp(1LL << n, {INF, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < (1LL << n); mask++) {
        if (dp[mask].ff == INF) continue;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1LL << i))) {
                int new_mask = mask | (1LL << i);
                // IF we add current

                auto r = dp[mask];
                if (r.ss + v[i] <= t) {
                    r.ss += v[i];
                } else {
                    r.ff++;
                    r.ss = v[i];
                }

                if (r < dp[new_mask]) {
                    dp[new_mask] = r;
                }
            }
        }
    }

    out(dp[(1 << n) - 1].ff);
}

signed main() {
    fastIO;
    solve();
    return 0;
}

