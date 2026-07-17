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

void solve() {
    int n, m;
    cin >> n >> m;
    
    int ans = 0;
    while (m > n) {
        if (m % 2 == 0) m /= 2;
        else m++;
        ans++;
    }
    ans += (n - m);
    cout << ans << endl;
}

signed main() {
    fastIO;
    solve();
    return 0;
}



// 0 1 2 3 4 5 6 7 8 9
// 