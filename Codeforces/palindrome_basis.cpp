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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, string, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

bool check(int n) {
    int rev = 0;
    int tmp = abs(n);

    while (tmp != 0) {
        rev = (rev * 10) + (tmp % 10);
        tmp = tmp / 10;
    }

    return (rev == abs(n));
}

// 502 palindromes
// 40004 max sum

int dp[40004][502];
signed main() {
    fastIO;

    vector<int> v;
    v.pb(0);

    rep(i, 1, 80008) {
        if (check(i)) {
            v.pb(i);
        }
    }

    rep(i, 1, 502) {
        dp[0][i] = 1;
    }

    rep(i, 1, 40004) {
        dp[i][0] = 0;
        
        rep(j, 1, 502) {
            if (v[j] <= i) {
                dp[i][j] = (dp[i][j - 1] + dp[i - v[j]][j]) % MOD1;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int a;
        in(a);

        out(dp[a][501]);
    }

    return 0;
}