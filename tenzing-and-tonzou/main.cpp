#include<bits/stdc++.h>

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;

    long long tenzing = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        tenzing += a;
    }

    long long tonzou = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tonzou += a;
    }

    if(tenzing > tonzou) {
        cout << "Tsondu" << endl;
    } else if(tenzing < tonzou) {
        cout << "Tenzing" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
