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
#define rv reverse
#define vt vector
#define str string

#define MOD1 1000000007
#define MOD2 998244353
#define INF LLONG_MAX

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void solve() {
    int n;
    in(n);

    vt<int> v(n);
    vin(v);

    vt<str> s(n);
    vt<str> r(n);

    rep(i, 0, n) {
        in(s[i]);
        r[i] = s[i];
        rv(all(r[i]));
    }

    vt<vt<int>> dp(n, vt<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = v[0];
    
    rep(i, 1, n) {
        if (s[i] >= s[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        } 
        
        if (s[i] >= r[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }

        if (r[i] >= s[i - 1] && dp[i - 1][0] != INF) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + v[i]);
        } 
        
        if (r[i] >= r[i - 1] && dp[i - 1][1] != INF) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
        }
    }

    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (ans == INF) {
        out(-1);
    } else {
        out(ans);
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}