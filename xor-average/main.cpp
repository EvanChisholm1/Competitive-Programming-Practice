#include<bits/stdc++.h>

using namespace std;

void solve(int n) {
    if(n % 2 == 0) {
        cout << 1 << " ";
        for(int i = 0; i < n - 2; i++) {
            cout << 2 << " ";
        }
        cout << 3 << endl;
    } else {
        for(int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
