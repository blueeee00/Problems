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

struct Ratio {
    int num, den;
    bool operator<(const Ratio& other) const {
        return (__int128)num * other.den < (__int128)other.num * den;
    }
};

int pwr(int b, int p) {
    int a = 1; b %= MOD2;
    while (p > 0) {
        if (p % 2 == 1) a = (a * b) % MOD2;
        b = (b * b) % MOD2;
        p /= 2;
    }

    return a;
}

int inv(int n) { return pwr(n, MOD2 - 2); }

void solve() {
    int n;
    in(n);

    vector<int> a(n), b(n);
    vin(a);
    vin(b);

    if (n < 2) {
        out(0);
        return;
    }

    int inv_a = 0;
    vector<Ratio> l1;
    l1.reserve(n * (n - 1) / 2);
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (a[i] > a[j]) inv_a++;
            l1.pb({a[i], a[j]});
        }
    }

    sort(all(l1));

    vector<Ratio> l2;
    l2.reserve(n * n);
    rep(p, 0, n) {
        rep(q, 0, n) {
            l2.push_back({b[q], b[p]});
        }
    }
    sort(all(l2));

    int sum = 0; 
    int ptr = 0;
    int l2sz = sz(l2);
    for (auto& x : l1) {
        while (ptr < l2sz && l2[ptr] < x) {
            ptr++;
        }
        
        sum += ptr;
    }

    int term1 = sum % MOD2;
    int term2 = (n % MOD2 * (inv_a % MOD2)) % MOD2;
    int n1 = (term1 - term2 + MOD2) % MOD2;
    int d = (n % MOD2 * ((n - 1) % MOD2)) % MOD2;
    out((n1 * inv(d)) % MOD2);
}

signed main() {
    fastIO;
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}