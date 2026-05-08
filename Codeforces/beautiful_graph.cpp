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

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD2;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD2;
        base = (base * base) % MOD2;
        exp /= 2;
    }
    return res;
}

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

    stack<int> st;
    st.push(0);

    vector<int> color(n, - 1);
    color[0] = 0;

    int black = 1, white = 0;
    while (!st.empty()) {
        auto node = st.top();
        st.pop();

        for (int neighbour: adj[node]) {
            if (color[neighbour] == -1) {
                color[neighbour] = 1 - color[node];
                if (color[neighbour] == 1) {
                    white++;
                } else {
                    black++;
                }

                st.push(neighbour);
            } else if (color[neighbour] == color[node]) {
                out(0);
                return;
            }
        } 
    }

    out((1 << black) + (1 << white));
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}