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
    int n, k;
    in(n, k);

    string x;
    in(x);

    vector<vector<int>> v(n + 1, vector<int>(2, 0));
    rep(i, 0, n) {
        v[i + 1][0] = v[i][0] + (x[i] == 'a');
        v[i + 1][1] = v[i][1] + (x[i] == 'b');        
    }

    // if (min(v[n - 1][0], v[n - 1][1]) <= k) {
    //     out(n);
    //     return;    
    // }

    int l = 0;
    int r = n;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool can = false;

        rep(i, mid, n + 1) {
            int a = v[i][0] - v[i - mid][0];
            int b = v[i][1] - v[i - mid][1];
        
            if (min(a, b) <= k) {
                can = true;
                break;
            }
        }

        if (can) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    out(ans);
}

signed main() {
    fastIO;
    solve();
    return 0;
}