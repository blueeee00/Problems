#include<bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int a, int b, int mod) {
    a %= mod;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int visited[100001];
int n, k;
vector<vector<int>> adj;
int sz;
void dfs(int x) {
    visited[x] = true;
    sz++;

    for (int u: adj[x]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

constexpr int MOD = 1000000007;

signed main() {
    cin >> n >> k;
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int u, v, x;
        cin >> u >> v >> x;

        if (x == 0) {
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            sz = 0;
            dfs(i);
            ans = (ans + modpow(sz, k, MOD)) % MOD;
        }
    }

    ans = (modpow(n, k, MOD) - ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}