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

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    string a;
    int n;
    in(a, n);

    vector<int> d(n);
    vin(d);

    int len = sz(a);
    int av = 0;
    for (char c : a) {
        av = av * 10 + (c - '0');
    }

    vector<int> can;
    if (len > 1) {
        int val = 0;
        for (int i = 0; i < len - 1; ++i) {
            val = val * 10 + d[n - 1];
        }

        can.pb(val);
    }

    int fd = -1;
    for (int c : d) {
        if (c > 0) {
            fd = c;
            break;
        }
    }
    if (fd != -1) {
        int val = fd;
        for (int i = 0; i < len; ++i) {
            val = val * 10 + d[0];
        }
        can.pb(val);
    } else {
        can.pb(0);
    }

    string p = "";
    for (int i = 0; i < len; ++i) {
        int target = a[i] - '0';
        
        for (int c : d) {
            if (i == 0 && len > 1 && c == 0) continue;
            
            if (c < target) {
                int val = 0;
                
                for (char ch : p) val = val * 10 + (ch - '0');
                val = val * 10 + c;
                
                for (int j = i + 1; j < len; j++) val = val * 10 + d[n - 1];
                can.push_back(val);
            } else if (c > target) {
                int val = 0;
                
                for (char ch : p) val = val * 10 + (ch - '0');
                val = val * 10 + c;

                for (int j = i + 1; j < len; j++) val = val * 10 + d[0];
                can.pb(val);
            } else {
                if (i == len - 1) {
                    int val = 0;
                
                    for (char ch : p) val = val * 10 + (ch - '0');
                    val = val * 10 + c;
                
                    can.push_back(val);
                }
            }
        }
        
        bool e = false;
        for (int c : d) {
            if (c == target) {
                e = true;
                break;
            }
        }
        
        if (e) {
            p += a[i];
        } else {
            break;
        }
    }

    int md = -1;
    for (int cand : can) {
        int diff = (cand >= av) ? (cand - av) : (av - cand);
        if (md == -1 || diff < md) {
            md = diff;
        }
    }

    out(md);
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}