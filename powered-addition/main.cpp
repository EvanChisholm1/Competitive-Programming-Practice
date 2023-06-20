#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxS = 0;

    for(int i = 1; i < n; i++) {
        int s = 0;
        while(a[i] < a[i - 1]) {
            s++;
            a[i] += pow(2, s - 1);
        }

        for(int j = s - 1; j > 0; j--) {
            if(a[i] - pow(2, j - 1) >= a[i - 1]) {
                a[i] -= pow(2, j - 1);
            }
        }

        maxS = max(s, maxS);
    }

    cout << maxS << endl;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        solve();
    }
}
