#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a = 0;
    for(int i = 2; i * i < n; i++) {
        if(n % i == 0) {
            a = i;
            break;
        }
    }

    if(a == 0) {
        cout << "NO" << endl;
        return;
    }

    int b = 0;
    for(int i = 2; i * i < n / a; i++) {
        if((n / a) % i == 0 && i != a) {
            b = i;
            break;
        }
    }

    if(b == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << a << " " << b << " " << n / (a * b) << endl;
}


int main() {
    int t;

    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }
}
