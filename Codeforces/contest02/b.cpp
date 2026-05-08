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

void solve() {
    int n;
    in(n);

    map<int, int> counts;
    rep(i, 0, n) {
        int a;
        in(a);
        counts[a]++;
    }

    vector<int> arr;
    
    int cur = 0;
    while (counts[cur]) {
        arr.pb(cur);
        cur++;
    }

    for (int i = 0; i < cur; i++) {
    counts[i]--;
    }

    vector<int> l;
    for (auto &[val, freq] : counts) {
        while (freq--) l.pb(val);
    }

    sort(rall(l));
    for (int x : l) arr.pb(x);

    int ans = 0;
    int mx = 0;
    int mex = 0;
    
    vector<int> freq(n + 1, 0);
    rep(i, 0, n) {
        int val = arr[i];
        mx = max(mx, val);
        
        if (val <= n) freq[val]++;
        while (mex <= n && freq[mex] > 0) mex++;

        // out(mx, mex);
        ans += (mx + mex);
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