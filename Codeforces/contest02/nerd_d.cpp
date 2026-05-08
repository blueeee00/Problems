#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
long long mod_exp(long long base, long long exp) {
    long long res = 1 % MOD;
    base %= MOD;
    while(exp) {
        if(exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        if(n < 2) {
            cout << 0 << '\n';
            continue;
        }
        vector<pair<long long, long long>> r;
        long long size = 1LL * n * (n - 1);
        r.reserve(size);
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(x != y) r.push_back({b[x], b[y]});
            }
        }
        auto cmp = [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
            return (long double)a.first * b.second < (long double)b.first * a.second;
        };
        sort(begin(r), end(r), cmp);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                pair<long long, long long> need{a[j], a[i]};
                total += (long long)(end(r) - upper_bound(begin(r), end(r), need, cmp));
            }
        }
        cout << (total % MOD) * mod_exp(size % MOD, 998244351) % MOD << '\n';
    }

    return 0;
}