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
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void solve() {
    int n, m, q;
    in(n, m, q);

    vector<int> a(n);
    vector<int> b(m);

    int sum_a = 0;
    int sum_b = 0;
    rep(i, 0, n) {
        in(a[i]);
        sum_a += a[i];
    }

    rep(j, 0, m) {
        in(b[j]);
        sum_b += b[j];
    }

    unordered_map<int, bool> pos_a;
    unordered_map<int, bool> pos_b;

    rep(i, 0, n) {
        pos_a[sum_a - a[i]] = true;
    }

    rep(j, 0, m) {
        pos_b[sum_b - b[j]] = true;
    }

    while (q--) {
        int x;
        in(x);

        bool ok = false;
        int abs_x = abs(x);
        for (int i = 1; i * i <= abs_x; i++) {
            if (abs_x % i == 0) {
                int d1 = i;
                int d2 = abs_x / i;

                if (pos_a[d1] && pos_b[x / d1]) {
                    ok = true;
                    break;
                }

                if (pos_a[d2] && pos_b[x / d2]) {
                    ok = true;
                    break;
                }

                if (pos_a[-d1] && pos_b[x / -d1]) {
                    ok = true;
                    break;
                }

                if (pos_a[-d2] && pos_b[x / -d2]) {
                    ok = true;
                    break;
                }
            }
        }

        if (ok) {
            out("YES");
        } else {
            out("NO");
        }
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}