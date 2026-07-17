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
    int n;
    in(n);

    vector<vector<int>> adj(n);
    rep(i, 0, n - 1) {
        int a, b;
        in(a, b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int b = 0;
    int w = 0;

    stack<int> st;
    st.push(0);

    vector<int> color(n, -1);
    color[0] = 0;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (color[node] == 0) {
            w++;
        } else if (color[node] == 1) {
            b++;
        }

        for (int neighbour: adj[node]) {
            if (color[neighbour] == -1) {
                color[neighbour] = 1 - color[node];
                st.push(neighbour);
            } else if (color[node] == color[neighbour]) {
                out(0);
                return;
            }
        }
    }

    out((b * w) - n + 1);
}

signed main() {
    fastIO;
    solve();
    return 0;
}