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

    vt<pair<int, int>> v(n);
    set<int> s;
    map<int, int> m;

    rep(i, 0, n) {
        int a;
        in(a);

        m[a]++;
        v[i] = {a, i};
    }

    sort(all(v));

    if (v[0].ff != 0) {
        out(-1);
        return;
    }

    vt<int> ans(n, -INF);

    int st = 0;
    int sum = 0;
    int mx = 0;
    rep(i, 1, sz(v)) {
        int cur = v[i].ff;
        int last = v[i - 1].ff;

        if (cur != last) {
            int q = (cur - sum) / (i - st);
            int r = (cur - sum) % (i - st);

            if (r != 0) {
                out(-1);
                return;
            }
            
            if (mx >= q + r) {
                out(-1);
                return;
            }

            rep(j, st, i) {
                ans[v[j].ss] = q + r;
                sum += q + r;
                
                r--;
                r = max(r, 0LL);
            }
            
            mx = max(mx, q + r);
            st = i;
        }
    }

    rep(i, 0, n) {
        if (ans[i] == -INF) {
            ans[i] = mx + 1;
        }
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
