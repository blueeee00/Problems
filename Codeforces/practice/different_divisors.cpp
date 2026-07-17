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

bool primes[1000005];
void cal() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i <= 1000000; i++) {
        if (!primes[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                primes[j] = true;
            }
        }
    }
}

void solve() {
    int n;
    in(n);

    int cnt = 1;
    int last = 1;
    int ans = 1;
    rep(i, 2, 1000001) {
        if (!primes[i] && i - last >= n) {
            ans *= i;
            last = i;
            cnt++;
        }

        if (cnt >= 3) {
            break;
        }
    }

    out(ans);
}

signed main() {
    fastIO;
    cal();

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}