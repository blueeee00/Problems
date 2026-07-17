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
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);

    int left = 0, right = n - 1;
    int last_left = -1, last_right = -1;

    int ans = 0;
    while (left <= right) {
        // cout << last_left << space << last_right << endl;

        if (left + 1 == right && v[left] == v[right]) {
            ans++;
        }

        if (last_left == v[left]) {
            ans++;
        }

        if (last_right == v[right]) {
            // cout << "ran\n";
            ans++;
        }

        bool swapped = false;
        if (v[left] != v[right] && v[right] == last_right && v[right] != last_left) {
            ans--;
            swapped = true;
        }

        if (v[left] != v[right] && v[left] == last_left && v[left] != last_right) {
            ans--;
            swapped = true;
        }

        if (swapped) {
            last_left = v[right];
            last_right = v[left];
        } else {
            last_left = v[left];
            last_right = v[right];
        }
        
        left++;
        right--;
    }

    cout << ans << endl;
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

//
// 1 1 1 2 3
// 1 2 1 1 3

// 1 3
// 2 1

// 2 1 2 2 1 1

// 2 1 2 2 1 1