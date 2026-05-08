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

    vector<string> v(n);
    vin(v);

    string ans = "";
    vector<pair<int,int>> cur = {{0, 0}};
    ans += v[0][0];

    for (int step = 1; step <= 2 * (n - 1); step++) {
        vector<pair<int,int>> nxt;
        char best = 'z';

        for (auto [i, j] : cur) {
            if (i + 1 < n) best = min(best, v[i + 1][j]);
            if (j + 1 < n) best = min(best, v[i][j + 1]);
        }

        for (auto [i, j] : cur) {
            if (i + 1 < n && v[i + 1][j] == best)
                nxt.pb({i + 1, j});
            if (j + 1 < n && v[i][j + 1] == best)
                nxt.pb({i, j + 1});
        }

        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());

        cur = nxt;
        ans += best;
    }

    cout << ans << '\n';
}

signed main() {
    fastIO;
    solve();
    return 0;
}
