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
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (auto &it: v) cin >> it;

    int left = 0, sum = 0, best = 0;
    for (int right = 0; right < n; right++) {
        sum += v[right];

        while (sum > t) {
            sum -= v[left];
            left++;
        }

        best = max(best, right - left + 1);
    }

    cout << best << endl;
}   

signed main() {
    fastIO;
    solve();
    return 0;
}

// 3 4 6 7
// 2 4 7

// 2 2 3
// 2 4 7