#include<bits/stdc++.h>
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

#define vin(v) for (auto &x : v) cin >> x
#define out(x) cout << x << endl
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);

    vector<pair<int, int>> srt;
    rep(i, 0, n) {
        srt.pb({v[i], i});
    }

    sort(all(srt), greater<pair<int, int>>());

    vector<int> g(n, -1);
    vector<int> l(n, -1);

    stack<int> st;
    rep(i, 0, n) {
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            g[i] = st.top();
        }

        st.push(i);
    }

    while (!st.empty()) st.pop();

    rep(i, n, 0) {
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }

        if (!st.empty()) {
            l[i] = st.top();
        }

        st.push(i);
    }

    vector<int> dp(n, 1);
    for (auto& p: srt) {
        int idx = p.ss;
        if (l[idx] != -1) {
            dp[idx] = max(dp[idx], dp[l[idx]] + 1);
        }

        if (g[idx] != -1) {
            dp[idx] = max(dp[idx], dp[g[idx]] + 1);
        }
    }

    int ans = 0;
    rep(i, 0, n) {
        ans = max(ans, dp[i]);
    }

    out(ans);
}

signed main() {
    fastIO;
    solve();
    return 0;
}
