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

set<int> s = {4, 8, 15, 16, 23, 42};
pair<int, int> find(int x) {
    for (int a: s) {
        for (int b: s) {
            if (a * b == x && a != b) {
                return {a, b};
            }
        }
    }

    return {0, 0};
}

void solve() {
    int ans[6];

    out("? 1 2");
    int a1;
    in(a1);

    pair<int, int> f1 = find(a1);

    out("? 2 3");
    int a2;
    in(a2);

    pair<int, int> f2 = find(a2);
    if (f1.first == f2.first || f1.first == f2.second) {
        ans[1] = f1.first;
        ans[0] = f1.second;
    } else {
        ans[1] = f1.second;
        ans[0] = f1.first;
    }
    
    ans[2] = (ans[1] == f2.first) ? f2.second : f2.first;

    out("? 4 5");
    int a3;
    in(a3);

    pair<int, int> f3 = find(a3);

    out("? 5 6");
    int a4;
    in(a4);

    pair<int, int> f4 = find(a4);
    if (f3.first == f4.first || f3.first == f4.second) {
        ans[4] = f3.first;
        ans[3] = f3.second;
    } else {
        ans[4] = f3.second;
        ans[3] = f3.first;
    }
    
    ans[5] = (ans[4] == f4.first) ? f4.second : f4.first;
    
    cout << "!";
    rep(i, 0, 6) {
        cout << space << ans[i];
    }

    cout << endl << flush;
}

signed main() {
    fastIO;
    solve();
    return 0;
}