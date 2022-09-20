#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    unordered_map<int, bool> rows;
    unordered_map<int, bool> cols;

    for (int i = 0; i < k; i++) {
        char direction;
        int location;
        cin >> direction >> location;

        if(direction == *"R") {
            if(rows.find(location) == rows.end()){
                rows[location] = true;
            } else {
                rows[location] = !rows[location];
            }
        } else {
            if(cols.find(location) == cols.end()) {
                cols[location] = true;
            } else {
                cols[location] = !cols[location];
            }
        }
    }

    int goldCells = 0;    

    for (int y = 1; y <= m; y++) {
        bool row;
        if(rows.find(y) == rows.end()) {
            row = false;
        } else {
            row = rows[y];
        }

        for (int x = 1; x <= n; x++) {
            bool col;
            if(cols.find(x) == cols.end()) {
                col = false;
            } else {
                col = cols[x];
            }

            if ((row + col) % 2) {
                // cout << "G";
                goldCells++;
            }
            // } else {
                // cout << "B";
            // }
        }

        // cout << "\n";
    }

    cout << goldCells << endl;

    return 0;
}
