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

    vector<int> v(n);
    vin(v);

    int last = 0;
    bool done = false;

    int idx_start = -1, idx_end = -1;
    rep(i, 0, n + 1) {
        if (i == n) {
            if (idx_end == -1) {
                idx_end = i;
            }

            if (idx_start > 0 && idx_end != -1 && v[idx_end - 1] < v[idx_start - 1]) {
                out("no");
                return;
            }

            continue;
        }

        int a = v[i];
        if (i == 0) {
            last = a;
            continue;
        }

        // out(last);
        if (last > a) {
            if (idx_start == -1) {
                idx_start = i - 1;
            }

            if (done) {
                out("no");
                return;
            }
        }

        if (idx_start != -1 && a > last && !done) {
            if (v[idx_start] > a) {
                out("no");
                return;
            } else {
                idx_end = i;
                if (idx_start > 0 && v[idx_end] < v[idx_start - 1]) {
                    out("no");
                    return;
                }

                done = true;
            }
        }

        last = a;
    }

    out("yes");
    if (idx_start == -1) {
        out(1, 1);
    } else if (idx_end == -1) {
        out(idx_start + 1, n);
    } else {
        out(idx_start + 1, idx_end);
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}