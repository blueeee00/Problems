#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int dn = n * 2;

    stack<int> st;
    vector<int> v;
    for (int i = 0; i < dn; i++) {
        int a;
        cin >> a;
        
       if (!st.empty() && st.top() == a) {
            st.pop();
            v.push_back(a);
        } else if (!st.empty() && ([&]{ auto t = st; t.pop(); return !t.empty() && t.top() == a; })()) {
            int t = st.top();
            st.pop();
            st.pop();
            v.push_back(a);
            v.push_back(t);

            st.push(t);
        } else {
            st.push(a);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    cout << '\n';

    sort(v.begin(), v.end());

    int last = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == last) {
            last++;
        }
    }

    cout << last << '\n';
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