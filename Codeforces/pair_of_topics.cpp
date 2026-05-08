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
    int n;
    cin >> n;
    
    vector<int> v1(n);
    vector<int> v2(n);

    for (auto &it: v1) cin >> it;
    for (auto &it: v2) cin >> it;

    vector<int> cal(n);
    forn(i, n) {
        cal[i] = v1[i] - v2[i];
    }

    sort(all(cal));

    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        if (cal[l] + cal[r] > 0) {
            ans += (r - l);
            r--;
        } else {
            l++;
        }
    }

    cout << ans << endl;
}

signed main() {
    fastIO;
    solve();
    return 0;
}

// 2 2 4 6 8
// 1 3 4 4 5

// 0 3 -2 5 -1
// -1 -2 0 3 5
// 4 + 2 + 1