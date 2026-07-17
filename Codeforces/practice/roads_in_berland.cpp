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

    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            in(dist[i][j]);
        }
    }

    int m;
    in(m);

    rep(i, 0, m) {
        int a, b, w;
        in(a, b, w);

        if (w < dist[a][b]) {
            dist[a][b] = w;
            dist[b][a] = w;
        
            rep(i, 1, n + 1) {
                rep(j, 1, n + 1) {
                    dist[i][j] = min(dist[i][j], dist[i][a] + dist[b][j] + w);
                    dist[i][j] = min(dist[i][j], dist[i][b] + dist[a][j] + w);
                }
            }
        }

        int sum = 0;
        rep(i, 1, n + 1) {
            rep(j, i + 1, n + 1) {
                sum += dist[i][j];
            }
        }

        cout << sum << space;
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}