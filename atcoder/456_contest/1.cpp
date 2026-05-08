#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (n); i++)
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

#define MOD1 1000000007
#define MOD2 998244353
#define INF LLONG_MAX

#define vin(v) for (auto &x : v) cin >> x
#define out(x) cout << x << endl
#define vout(v) for (auto &x : v) cout << x << space; cout << endl

void solve() {
    int n;
    cin >> n;

    if (n >= 6 && n <= 21) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    fastIO;
    solve();
    return 0;
}