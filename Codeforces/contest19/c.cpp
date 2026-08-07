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

    string x, y;
    in(x, y);

    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    vt<vt<int>> pos1(2);
    vt<vt<int>> pos2(2);
    rep(i, 0, n) {
        if (x[i] == '1') {
            if (i % 2 == 0) {
                pos1[0].pb(i);
                x1++;
            } else {
                pos1[1].pb(i);
                x2++;
            }
        }

        if (y[i] == '1') {
            if (i % 2 == 0) {
                y1++;
                pos2[0].pb(i);
            } else {
                pos2[1].pb(i);
                y2++;
            }
        }
    }

    if (x1 != y1 || x2 != y2) {
        out(-1);
        return;
    }

    int cnt = 0;
    rep(i, 0, sz(pos1[0])) {
        cnt += abs(pos1[0][i] - pos2[0][i]) / 2;
    }

    rep(i, 0, sz(pos1[1])) {
        cnt += abs(pos2[1][i] - pos1[1][i]) / 2;
    }

    out(cnt);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}