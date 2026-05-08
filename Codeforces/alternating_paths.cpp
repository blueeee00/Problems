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

void solve() {
    int n, m;
    in(n, m);

    vector<vector<int>> adj(n);
    rep(i, 0, m) {
        int a, b;
        in(a, b);
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> color(n, -1);

    int ans = 0;
    rep(i, 0, n) {
        if (color[i] != -1) continue;

        stack<int> st;
        st.push(i);

        int black = 0;
        int white = 0;

        color[i] = 0;

        bool allowed = true;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (color[node] == 0) {
                black++;
            } else {
                white++;
            }

            for (int neighbour: adj[node]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - color[node];
                    st.push(neighbour);
                } else if (color[neighbour] == color[node]) {
                    allowed = false;
                }
            }
        }

        if (allowed) {
            ans += max(black, white);
        }
    }

    out(ans);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}