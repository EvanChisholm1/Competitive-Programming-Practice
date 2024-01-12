#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n < 4) {
        cout << 0 << endl;
        return 0;
    }

    int p = 0;

    for(int i = 1; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                p++;
            }
        }
    }

    cout << p << endl;
    return 0;
}
