#include<bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ind[n+1];

    map<int, ll> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int a = x - i;
        ind[i] = a;
        if(m.find(a) == m.end()) {
            m[a] = 1;
        } else {
            m[a] += 1;
        }
    }

    ll count = 0;

    for(int i = 0; i < n; i++) {
        m[ind[i]] -= 1;
        count += m[ind[i]];
    }

    cout << count << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
