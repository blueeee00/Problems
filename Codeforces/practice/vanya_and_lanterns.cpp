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
    int n, l;
    cin >> n >> l;

    vector<int> v(n);
    vin(v);
    sort(all(v));

    int max_gap = 2 * v[0];
    for (int i = 1; i < n; i++) {
        max_gap = max(max_gap, v[i] - v[i-1]);
    }

    max_gap = max(max_gap, 2 * (l - v[n-1])); 
    cout << fixed << setprecision(10) << (double) max_gap / 2.0 << endl;
}

signed main() {
    fastIO;
    solve();
    return 0;
}

// 0 1 2 3 4 5
// . . # . . #

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// # . . # . # . # . # .  .  .  .  .  #  #
// 0 1 

// 0 3 5 7 9 14 15
// . 3 2 2 2 5 1