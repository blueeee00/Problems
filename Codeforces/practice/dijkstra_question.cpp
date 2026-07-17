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

void solve() {
    int n, m;
    in(n, m);

    vector<vector<pair<int, int>>> adj(n);
    rep(i, 0, m) {
        int a, b, c;
        in(a, b, c);
        a--; b--;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    parent[0] = -1;
    dist[0] = 0;

    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int u = node.ss;
        int d = node.ff;

        if (d > dist[u]) {
            continue;
        }

        for (auto &p: adj[u]) {
            int v = p.ss;
            int w = p.ff;

            if (dist[u] + w < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }

        }
    }

    if (parent[n - 1] == -1) {
        out(-1);
        return;
    }

    int cur = n - 1;
    vector<int> v;
    while (cur != -1) {
        v.pb(cur + 1);
        cur = parent[cur];
    }

    reverse(all(v));
    vout(v);
}

signed main() {
    fastIO;
    solve();
    return 0;
}