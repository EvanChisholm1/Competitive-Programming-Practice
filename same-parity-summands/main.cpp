#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll r1 = (n - 2 * (k - 1));
    if(r1 > 0 && r1 % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < k-1; i++) cout << "2 ";
        cout << r1 << endl;
        return;
    }

    ll r2 = (n - (k-1));
    if(r2 > 0 && r2 % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k-1; i++) cout << "1 ";
        cout << r2 << endl;
        return;
    }

    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}
