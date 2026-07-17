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

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

int cnt(int n, int lim) {
    if (lim <= 0) return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    rep(i, 1, n + 1) {
        for (int j = 1; j <= lim && j <= i; j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD1;
        }
    }

    return dp[n];
}

void solve() {
    int n, k, d;
    in(n, k, d);

    int valid = cnt(n, k);
    int invalid = cnt(n, d - 1);

    out((valid - invalid + MOD1) % MOD1);
}

signed main() {
    fastIO;
    solve();
    return 0;
}