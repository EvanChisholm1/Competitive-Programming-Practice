#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int taxis[5];
    memset(taxis, 0, sizeof(taxis));

    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;

        taxis[p]++;
    }

    int totalTaxis = 0;

    for(int i = 0; i < n; i++) {
        int t = 0;
        for(int k = 3; k > 0; k--) {
            while(t + k <= 4 && taxis[k] > 0) {
                t += k;
                taxis[k]--;
            }
        }
        if(t > 0) totalTaxis++;
        else break;
    }

    totalTaxis += taxis[4];

    cout << totalTaxis << endl;
    return 0;
}
