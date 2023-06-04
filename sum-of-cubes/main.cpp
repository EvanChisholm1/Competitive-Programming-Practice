#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    for(long long i = 1; i < cbrt(n); i++) {
        long long d = n - pow(i, 3);
        double r = cbrt(d);

        if(floor(r) == r) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
