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
    int n, k;
    in(n, k);
    string s;
    in(s);

    vector<char> pattern(k, '?');
    rep(i, 0, n) {
        if (s[i] != '?') {
            int mod_idx = i % k;
            if (pattern[mod_idx] != '?' && pattern[mod_idx] != s[i]) {
                out("NO");
                return;
            }
            
            pattern[mod_idx] = s[i];
        }
    }

    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, k) {
        if (pattern[i] == '0') cnt0++;
        else if (pattern[i] == '1') cnt1++;
    }

    if (cnt0 <= k / 2 && cnt1 <= k / 2) {
        out("YES");
    } else {
        out("NO");
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}