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

    vt<int> a(n);
    vt<int> b(n);
    vin(a, b);

    int one_cnt = 0;
    int zero_cnt = 0;

    int one = 0;
    int zero = 0;

    int b_one = 0;
    int b_zero = 0;

    bool ok = true;
    rep(i, 0, n) {
        if (a[i] == 0) {
            zero++;
        } else {
            one++;
        }

        if (b[i] == 0) {
            b_zero++;
        } else {
            b_one++;
        }
    
        if (a[i] == 1 && b[i] == 0) {
            one_cnt++;
        }

        if (a[i] == 0 && b[i] == 1) {
            zero_cnt++;
        }

        if (a[i] != b[i]) {
            ok = false;
        }
    }

    if (ok) {
        out(0);
        return;
    }
    
    if (one == 0 && b_one != 0) {
        out(-1);
        return;
    }

    if (zero != 0 && b_zero == 0) {
        out(-1);
        return;
    }

    if (one_cnt % 2 == 0) {
        out(2);
        return;
    }

    if (one_cnt % 2 == 1) {
        out(1);
        return;
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}