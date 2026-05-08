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

    vector<int> v(n);
    vin(v);

    vector<vector<int>> v1(n);
    rep(i, 0, n - 1) {
        int t, c;
        in(t, c);
        t--;
        c--;
        v1[t].pb(c);
        v1[c].pb(t);
    }

    // dfs
    stack<pair<int, pair<int, int>>> st;
    st.push({0, {-1, v[0]}});

    int ans = 0;
    while (!st.empty()) {
        auto node = st.top();
        st.pop();

        if (node.ss.ss > m) continue;

        bool leaf = true;
        for (auto neighbour: v1[node.ff]) {
            if (neighbour != node.ss.ff) {
                leaf = false;
                int c = (v[neighbour] == 1) ? node.ss.ss + 1 : 0;
                st.push({neighbour, {node.ff, c}});
            }
        }

        if (leaf) {
            ans++;
        }
    }
    
    out(ans);
}

signed main() {
    fastIO;
    solve();
    return 0;
}