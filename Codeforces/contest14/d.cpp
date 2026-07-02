#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    // ts is not mine

    ll n;
    cin >> n;
    vector<ll> a(n), b(n), diff(n, 0);
    vin(a); vin(b); 
    for (ll i=n-1; i>=0; i--) {
        cout << diff[i] << ' ';
        diff[i] = b[i] - a[i] - diff[i];
        cout << diff[i] << ' ';
        cout << endl;
        if (diff[i] < 0) {
            if (i-1 < 0) {
                cout << "NO\n";
                return;
            } else {
                diff[i-1] = diff[i] * -1;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}