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

struct interval {
    int l, r;
};

void solve() {
    int n;
    in(n);

    vector<interval> v(n);
    map<pair<int, int>, int> freq;
    rep(i, 0, n) {
        in(v[i].l, v[i].r);
        freq[{v[i].l, v[i].r}]++;
    }
    
    vector<interval> v1 = v;
    vector<int> ans(n, 0);
    rep(i, 0, 2) {
        vector<int> ord(n);
        iota(all(ord), 0);

        sort(all(ord), [&v](int i, int j) {
            if (v[i].l != v[j].l)
                return v[i].l < v[j].l;

            return v[i].r > v[j].r;
        });

        set<int> b;
        for (int i: ord) {
            auto it = b.lb(v[i].r);
            if (it != b.end()) {
                ans[i] += *it - v[i].r;
            }

            b.insert(v[i].r);
        }

        for (auto &s: v) {
            s.l *= -1;
            s.r *= -1;

            swap(s.l, s.r);
        }
    }

    rep(i, 0, n) {
        if (freq[{v1[i].l, v1[i].r}] > 1) {
            out(0);
            continue;
        }
        
        out(ans[i]);
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}