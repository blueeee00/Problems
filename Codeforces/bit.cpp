#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<char, int> ns;
    for (int i = 0; i < 4; i++) {
        string x;
        cin >> x;

        for (int j = 0; j < 4; j++) {
            ns[x[j]]++;
        }
    }

    for (auto [c, d]: ns) {
        if (c == '.') continue;
        if (d > n * 2) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}