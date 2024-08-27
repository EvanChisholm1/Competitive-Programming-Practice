#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int p[n+1];

    for(int i = 0; i < n; i++) cin >> p[i];

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1 || (p[i-1] < p[i]) != (p[i] < p[i+1]))
            ans.push_back(p[i]);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) solve();
    return 0;
}
