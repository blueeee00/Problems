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

    vector<int> c(n);

    int cnt = 0;
    int sum = 0;
    int t1 = 0;
    rep(i, 0, n) {
        in(c[i]);

        // if more than 2 then u can do the 1 2 1 2 
        if (c[i] >= 2) {
            cnt++;
            sum += c[i];

            // how many times uc an do
            t1 += (c[i] + c[i] / 2 - 1);
        }
    }

    if (cnt == 0) {
        out(0);
        return;
    }

    if (cnt == 1) {
        int d = 0;
        rep(i, 0, n) {
            if (c[i] >= 2) {
                d = c[i];
                break;
            }
        }

        int ans = d + min(n - 1, d / 2);
        if (ans < 3) {
            out(0);
        } else {
            out(ans);
        }

    } else {
        int t2 = sum - cnt + n;
        int ans = min(t1, t2);

        out(ans);
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}