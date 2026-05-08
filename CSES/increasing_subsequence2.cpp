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

    vector<int> ans;
    ans.push_back(v[0]);

    vector<int> dp(n);
    dp[0] = 1;

    rep(i, 0, n) {
        if (ans.back() < v[i]) {
            ans.pb(v[i]);
            out(sz(ans));
            dp[i] = dp[i - 1] + (1 << sz(ans) - 1);
        } else {
            int low = lb(all(ans), v[i]) - ans.begin();
            // cout << low << endl;
            ans[low] = v[i];
            
            if (i != 0) {
                dp[i] = dp[i - 1] + 1;
            }
        }

    }

    // vout(ans);
    out(dp[n - 1]);
    // out(sz(ans));
}

signed main() {
    fastIO;
    solve();
    return 0;
}

// 2 1 3
// 1 2 3 

// 1 3 7 15

// 