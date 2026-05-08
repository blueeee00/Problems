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

    vector<int> cnt(10, 0);
    int sum = 0;
    rep(i, 0, n) {
        int a;
        in(a);

        sum += a;
        cnt[a]++;
    }

    if (cnt[0] == 0) {
        out(-1);
        return;
    }

    int rem = sum % 3;
    auto remove_n = [&](vector<int> digits, int num_to_remove) {
        int removed = 0;
        for (int d : digits) {
            while (cnt[d] > 0 && removed < num_to_remove) {
                cnt[d]--;
                removed++;
            }
        }
        return removed == num_to_remove;
    };

    if (rem != 0) {
        bool found = false;
        for (int i: {1, 4, 7, 2, 5, 8}) {
            if (rem == 1 && (i == 1 || i == 4 || i == 7) && cnt[i] > 0) {
                cnt[i]--;
                found = true;
                break;
            }

            if (rem == 2 && (i == 2 || i == 5 || i == 8) && cnt[i] > 0) {
                cnt[i]--;
                found = true;
                break;
            }
        }

        if (!found) {
            int c = 2;
            for (int i: {1, 4, 7, 2, 5, 8}) {
                while (c > 0 && cnt[i] > 0) {
                    if (rem == 2 && (i == 2 || i == 5 || i == 8)) {
                        cnt[i]--;
                        c--;
                    } else if (rem == 1 && (i == 1 || i == 4 || i == 7)) {
                        cnt[i]--;
                        c--;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    bool has = false;
    rep(i, 1, 10) {
        if (cnt[i]) has = true;
    }

    if (has) {
        rep(i, 9, 0) {
            while (cnt[i]--) {
                cout << i;
            }
        }
    } else {
        out(0);
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}