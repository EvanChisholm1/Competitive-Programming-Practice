#include<bits/stdc++.h>

using namespace std;

int m, n; 

map<int, vector<vector<int>>> numberMap;
map<int, bool> history;

bool search(int a, int b, int c) {
    int x = a * b;
    if(history.find(x) != history.end() && history[x]) {
        return false;
    } else {
        history[x] = true;
    }

    vector<vector<int>> xList = numberMap[x];

    for(int i = 0; i < xList.size(); i++) {
        vector<int> coords = xList[i];

        if(coords[0] == 1 && coords[1] == 1) {
            return true;
        }
        if(search(coords[0], coords[1], c + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            if(numberMap.find(num) != numberMap.end()) {
                vector<int> coords = {i, j};
                numberMap[num].push_back(coords);
            } else {
                vector<vector<int>> coords = {{i, j}};
                numberMap[num] = coords;
            }
        }
    }

    if(search(m, n, 0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}

