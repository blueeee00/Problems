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
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void solve() {
    int n;
    in(n);

    vector<int> v1(n);
    vector<int> v2(n);
    vin(v1);
    vin(v2);

    map<pair<int, int>, int> m;
    int add = 0;
    rep(i, 0, n) {
        if (v1[i] == 0 && v2[i] == 0) {
            add++;            
        }

        if (v1[i] != 0) {
            int d = -v2[i];
            int o = v1[i];

            int g = gcd(-v2[i], v1[i]);
            d /= g;
            o /= g;

            if (o < 0) {
                d = -d;
                o = -o;
            }

            m[{d, o}]++;
        }
    }

    int ans = add;
    for (auto &[_, cnt]: m) {
        ans = max(ans, cnt + add);
    }

    out(ans);
}

signed main() {
    fastIO;
    solve();
    return 0;
}