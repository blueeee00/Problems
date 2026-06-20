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
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void solve() {
    int hp, n;
    in(hp, n);

    vector<int> attacks(n);
    vector<int> cooldowns(n);
    vin(attacks, cooldowns);

    int low = 0, high = 1e12;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2LL;    
        int dmg = 0LL;
        bool ok = false;
        rep(i, 0, n) {
            int cur = ((mid / cooldowns[i]) + 1) * attacks[i];
            
            if (hp - dmg <= cur) {
                ok = true;
                break;
            }

            dmg += cur;
        }

        if (ok) {
            high = mid - 1LL;
            ans = mid;
        } else {
            low = mid + 1LL;
        }
    }

    out(ans + 1LL);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}