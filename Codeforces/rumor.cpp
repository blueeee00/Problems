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

// Variadic I/O
#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

vector<vector<int>> adj;
vector<bool> visisted;
vector<int> price;
int dfs(int start, int mn) {
    mn = min(mn, price[start]);

    for (int neighbour: adj[start]) {
        if (visisted[neighbour]) continue;
        visisted[neighbour] = true;
        mn = min(mn, dfs(neighbour, mn));
    }

    return mn;
}

void solve() {
    int n, m;
    in(n, m);

    // out(n, m);
    adj.resize(n);
    price.resize(n);
    visisted.resize(n, false);
    vin(price);
    
    rep(i, 0, m) {
        int a, b;
        in(a, b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    rep(i, 0, n) {
        if (visisted[i]) continue;
        // out(i);
        ans += dfs(i, INF);
    }

    out(ans);
}

signed main() {
    fastIO;
    solve();
    return 0;
}