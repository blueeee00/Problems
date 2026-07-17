#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        int sum = a + b + c;

        if (sum >= 2) ans++;
    }

    cout << ans;
    return 0;
}