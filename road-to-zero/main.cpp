#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    if(2 * a < b) {
        cout << a * x + a * y << endl;
    } else {
        cout << min(x, y) * b + (max(x, y) - min(x, y)) * a << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}
