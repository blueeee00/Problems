#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<ll> sixs;
    vector<ll> threes;
    vector<ll> twos;
    vector<ll> ones;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        
        if (a % 2 == 0 && a % 3 == 0) {
            sixs.push_back(a);
        } else if (a % 2 == 0 && a % 3 != 0) {
            twos.push_back(a);
        } else if (a % 2 != 0 && a % 3 == 0) {
            threes.push_back(a);
        } else {
            ones.push_back(a);
        }
    }

    for (int i = 0; i < sixs.size(); i++) {
        cout << sixs[i] << ' ';
    }

    
    for (int i = 0; i < twos.size(); i++) {
        cout << twos[i] << ' ';
    }
    
    for (int i = 0; i < ones.size(); i++) {
        cout << ones[i] << ' ';
    }
    
    for (int i = 0; i < threes.size(); i++) {
        cout << threes[i] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}