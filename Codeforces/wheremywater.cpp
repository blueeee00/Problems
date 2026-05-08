#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    ll h;
    cin >> h;

    vector<ll> pool(n);
    for (int i = 0; i < n; i++) {
        cin >> pool[i];
    }

    vector<ll> cnt(n);
    for (int i = 0; i < n; i++) {
        ll curr = pool[i];
        cnt[i] = h - curr;

        for (int j = i+1; j < n; j++) {
            curr = max(curr, pool[j]);
            cnt[i] += h - curr;
        }

        curr = pool[i];

        for (int j = i-1; j >= 0; j--) {
            curr = max(curr, pool[j]);
            cnt[i] += h - curr;
        }
    }

    ll best = 0;
    for (int i = 0; i < n; i++) {
        ll mx = pool[i];
        int mid = i;
        
        for (int j = i; j < n; j++) {
            if (pool[j] > mx) {
                mx = pool[j];
                mid = j;
            }

            best = max(cnt[j] + cnt[i] - cnt[mid], best);
        }
    }

    cout << best << '\n';
}

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