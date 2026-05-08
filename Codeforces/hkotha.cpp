#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// This helper function counts subarrays with length in [L, R] 
// that have AT MOST K distinct elements.
long long countAtMost(int n, int k, int L, int R, const vector<int>& a) {
    if (k <= 0) {
        if (k == 0) return 0; // Exactly 0 distinct is impossible here
        return 0;
    }
    
    long long total = 0;
    unordered_map<int, int> freq;
    int distinct = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        if (freq[a[right]] == 0) distinct++;
        freq[a[right]]++;

        // Shrink window if we have too many distinct elements
        while (distinct > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) distinct--;
            left++;
        }

        int start_max = right - L + 1;
        int start_min = max(left, right - R + 1);

        if (start_min <= start_max) {
            total += (start_max - start_min + 1);
        }
    }
    return total;
}

void solve() {
    int n, k, l, r;
    if (!(cin >> n >> k >> l >> r)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long result = countAtMost(n, k, l, r, a) - countAtMost(n, k - 1, l, r, a);
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}