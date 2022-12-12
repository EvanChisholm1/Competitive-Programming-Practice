#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;

    bool sizes[t + 1];
    memset(sizes, false, sizeof(sizes));
    sizes[0] = true;

    for(int i = 0; i <= t; i++) {
        if(sizes[i]) {
            if(i + a <= t) sizes[i + a] = true;
            if(i + b <= t) sizes[i + b] = true;
        }
    }

    for(int i = 1; i <= t; i++) {
        if(sizes[i]) {
            int halfFullness = floor(float(i) / 2);
            sizes[halfFullness] = true;
        }
    }

    for(int i = 0; i <= t; i++) {
        if(sizes[i]) {
            if(i + a <= t) sizes[i + a] = true;
            if(i + b <= t) sizes[i + b] = true;
        }
    }

    int maxFullness = 0;

    for(int i = t; i > 0; i--) {
        if(sizes[i]) {
            maxFullness = i;
            cout << maxFullness << endl;
            return 0;
        }
    }

    cout << maxFullness << endl;
    return 0;
}
