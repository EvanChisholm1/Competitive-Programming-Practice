#include<bits/stdc++.h>

using namespace std;

int main() {
    int g, p;
    cin >> g >> p;

    bool gates[g + 1];
    memset(gates, false, sizeof(gates));

    bool isClosed = false;
    int maxPlanes = 0;

    for(int i = 0; i < p; i++) {
        int plane;
        cin >> plane;

        if(isClosed) continue;

        bool foundSpot = false;
        for(int j = min(plane, g); j > 0; j--){
            if(gates[j] == false) {
                foundSpot = true;
                gates[j] = true;
                maxPlanes++;
                break;
            }
        }

        if(!foundSpot) {
            isClosed = true;
        }
    }

    cout << maxPlanes << endl;

    return 0;
}
