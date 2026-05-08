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

#define vin(v) for (auto &x : v) cin >> x
#define out(x) cout << x << endl
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);

    vector<int> pf(n + 1), sf(n);
    for (int i = 1; i < n; i++) {
        pf[i + 1] = pf[i] + abs(v[i]);
    }

    for (int i = n - 1; i >= 1; i--) {
        sf[i - 1] = sf[i] - v[i];
    }

    int ans = sf[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, v[0] + sf[i] + pf[i]);
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

// 2 states
// i is index
// j is picked first or second
// MAXIMUM val

// IF we picked first we can pick i and i + 1
// IF we picked second we can pick i - 1 and i + 1

// 1 + 4 + 3

// 3 + 

// -2 -3 -4 10 -9
// 3 + 

// 