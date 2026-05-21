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

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    in(n);

    vector<int> v(n);
    vin(v);

    int mx = v[0];
    int k = 0;
    rep(i, 1, n) {
        if (v[i] < mx) {
            k = max(k, mx - v[i]);
        }
        mx = max(mx, v[i]);
    }
    
    if (k == 0) {
        out("YES");
        return;
    }

    int prev = v[0];
    rep(i, 1, n) {
        int a = v[i];
        int b = v[i] + k;
        int n = INT_MAX;

        if (a >= prev) {
            n = min(n, a);
        }
        
        if (b >= prev) {
            n = min(n, b);
        }

        if (n == INT_MAX) {
            out("NO");
            return;
        }

        prev = n;
    }

    out("YES");
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}