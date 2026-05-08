#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> lvls(m, 0);
        int curr = n;

        // for every sec
        for (int i = 0; i < l; i++) {
            // 
            
            lvls[min(m, curr + 1) - 1]++;
            sort(lvls.begin(), lvls.end(), greater<int>());

            if (curr > 0 && a[n - curr] - 1 == i) {
                lvls[0] = 0;
                sort(lvls.begin(), lvls.end(), greater<int>());
                curr--;
            }
        }

        cout << lvls[0] << '\n';
    }

    return 0;
}

// 1 2 10
// 10
// 1 1 2 2 3 3 

// 