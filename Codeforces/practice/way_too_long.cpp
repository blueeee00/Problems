#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string x;
        cin >> x;

        int l = x.length();

        if (l <= 10) {
            cout << x;
        } else {
            cout << x[0] << l - 2 << x[l - 1];
        }
        
        cout << '\n';
    }
    
    return 0;
}