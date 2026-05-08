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
#define outl(x) cout << x
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

void encode() {
    int n;
    cin >> n;

    rep(i, 0, n) {
        string cur = "aaaaaaa";
        int a;
        cin >> a;
        rep(i, 0, 7) {
            cur[i] = (a % 26) + 'a';
            a /= 26;
        }
        
        outl(cur);
    }
}

void decode() {
    string x;
    cin >> x;

    vector<int> v(sz(x) / 7);
    for (int i = 0; i < sz(x); i += 7) {
        string u = x.substr(i, 7);
        int a = 0;

        rep(i, 7, 0) {
            a = a * 26 + (u[i] - 'a');
        }
        v[i / 7] = a;
    }

    out(sz(v));
    vout(v);
}

void solve() {
    string cmd;
    cin >> cmd;
    
    if (cmd == "first") {
        encode();
    } else {
        decode();
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}