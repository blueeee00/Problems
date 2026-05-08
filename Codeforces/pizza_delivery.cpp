#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = {a, 0};
    }
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = {v[i].first, a};
    }

    vector<vector<int>> dp(n, vector<int>(n));
}

// 2d dp
// from a to b

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}