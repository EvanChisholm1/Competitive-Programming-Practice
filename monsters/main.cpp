#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> m;

    for(int i = 0; i < n; i++) {
        pair<int, int> p;
        p.second = i;
        cin >> p.first;
        p.first = p.first % k;
        if(p.first == 0) p.first = k;

        m.push_back(p);
    }

    sort(m.begin(), m.end(), cmp);

    for(auto x: m) {
        cout << x.second + 1 << " ";
        // cout << x.first << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}