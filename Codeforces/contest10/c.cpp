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
    int a, b, x;
    in(a, b, x);

    int ans = abs(a - b);
    int t = 0;
    while (a != 0 || b != 0) {
        if (a > b) {
            a = floor((double) a / x);
        } else {
            b = floor((double) b / x);
        }
        
        t++;
        if (a == b) {
            ans = min(ans, t);
            break;
        }

        ans = min(ans, t + abs(a - b));
    }

    out(ans);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

    // if (x > max(a, b)) {
    //     ans = min(ans, 2LL);
    // }
