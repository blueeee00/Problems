#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define fastIO ios_base::sync_with_stdio(false);
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

int query(int x, int y) {
    cout << "? " << x << " " << y << endl; 

    int res;
    if (!(cin >> res) || res == -1) {
        exit(0);
    }
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    int ans = -1;
    bool found = false;

    for (int i = 1; i < n; i++) {
        if (query(2 * i + 1, 2 * i + 2)) {
            ans = 2 * i + 1;
            found = true;
            break;
        }
    }

    if (!found) {
        if (query(1, 3)) {
            ans = 1;
        } else {
            if (query(1, 4)) {
                ans = 1;
            } else {
                ans = 2;
            }
        }
    }

    cout << "! " << ans << endl;
}

signed main() {
    fastIO;
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}

// 6 2