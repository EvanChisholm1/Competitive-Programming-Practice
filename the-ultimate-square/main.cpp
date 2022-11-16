#include<bits/stdc++.h>

using namespace std;

void solve(int n) {
    printf("%d \n", int(ceil(float(n) / 2)));
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
