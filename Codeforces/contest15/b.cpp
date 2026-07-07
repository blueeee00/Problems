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

    vt<vt<int>> cnt(n + 1, vt<int>(4, 0));
    vt<int> c(n + 1, 0);
    rep(i, 1, n + 1) {
        cnt[i][1] = cnt[i - 1][1];
        cnt[i][2] = cnt[i - 1][2];
        cnt[i][3] = cnt[i - 1][3];

        cnt[i][v[i - 1]]++;
        c[i] = (2 * cnt[i][3]) - i;
    }

    vt<int> s(n + 1, 0);
    s[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        s[i] = min(s[i + 1], c[i]);
    }

    bool ok = false;
    rep(i, 1, n - 1) {
        if (2 * cnt[i][1] >= i && s[i + 1] <= c[i]) {
            ok = true;
            break;
        }
    }

    if (ok) {
        out("YES");
    } else {
        out("NO");
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}