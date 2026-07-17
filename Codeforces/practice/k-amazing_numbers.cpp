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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, string, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void solve() {
    int n;
    in(n);

    vector<vector<int>> pos(n + 1);
    rep(i, 0, n) {
        int val;
        in(val);

        pos[val].pb(i + 1);
    }

    vector<int> ans(n + 1, INF);
    rep(i, 1LL, n + 1) {
        if (pos[i].empty()) continue;

        int mx = 0;
        int last = 0;

        for (int v: pos[i]) {
            mx = max(mx, v - last);
            last = v;
        }

        mx = max(mx, n + 1 - last);
        ans[mx] = min(ans[mx], i);
    }

    rep(i, 1, n + 1) {
        ans[i] = min(ans[i], ans[i - 1]);
    }

    rep(i, 1, n + 1) {
        if (ans[i] == INF) {
            cout << -1 << space;
        } else {
            cout << ans[i] << space;
        }
    }

    out();
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}