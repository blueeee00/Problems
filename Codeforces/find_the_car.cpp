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
    int n, k, m;
    in(n, k, m);

    vector<int> v1(k + 1, 0);
    vector<int> v2(k + 1, 0);
    rep(i, 1, k + 1) {
        in(v1[i]);
    }

    rep(i, 1, k + 1)  {
        in(v2[i]);
    }

    vector<int> ans(m);
    rep(i, 0, m) {
        int q;
        in(q);
        https://open.spotify.com/track/4ydmav4vl7hebadtfZtMrg?si=cc0a4311da154c50
        if (q == 0) {
            ans[i] = 0;
            continue;
        }

        auto it = upper_bound(all(v1), q);

        if (it == v1.end()) {
            ans[i] = v2[k];
            continue;
        }

        int r = distance(v1.begin(), it);
        int l = r - 1;
        ans[i] = v2[l] + ((q - v1[l]) * (v2[r] - v2[l])) / (v1[r] - v1[l]);
    }

    vout(ans);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}