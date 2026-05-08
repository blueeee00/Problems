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
    string n;
    cin >> n;

    int l = sz(n);
    int sum = 0;
    vector<int> v;
    rep(i, 0, l) {
        int digit = n[i] - '0';
        sum += digit;
        v.push_back(digit - (i == 0));
    }

    sort(all(v));

    int ans = 0;
    while (!v.empty() && sum > 9) {
        sum -= v.back();
        v.pop_back();
        ans++;
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