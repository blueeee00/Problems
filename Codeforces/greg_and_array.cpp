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
    int n, k, m;
    in(n, k, m);

    vector<int> v(n);
    vin(v);

    vector<tuple<int, int, int>> o;
    rep(i, 0, m) {
        int a, b, c;
        in(a, b, c);

        o.pb({a, b, c});
    }

    vector<int> s(n + 1);
    rep(i, 0, k) {
        int l, r;
        in(l, r);
        l--;
        r--;

        s[l]++;
        s[r + 1]--;
    }

    vector<int> pref(n + 2);

    int cur = 0;
    rep(i, 0, m) {
        cur += s[i];
        pref[get<0>(o[i])] += cur * get<2>(o[i]);
        pref[get<1>(o[i]) + 1] -= cur * get<2>(o[i]);
    }

    int c = 0;
    rep(i, 0, n) {
        c += pref[i + 1];
        cout << v[i] + c << space;
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}