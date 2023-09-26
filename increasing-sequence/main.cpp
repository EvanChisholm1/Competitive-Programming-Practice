#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int prev;
    if(a[0] > 1) prev = 1;
    else prev = 2;

    for(int i = 1; i < n; i++) {
        if(a[i] == prev + 1) prev = prev + 2;
        else prev = prev + 1;
    }

    cout << prev << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}

