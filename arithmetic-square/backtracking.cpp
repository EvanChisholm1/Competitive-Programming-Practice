#include<bits/stdc++.h>

using namespace std;

string grid[3][3];
int XS = 0;

bool verifyHorizontal(int y) {
    string h[3];

    for (int i = 0; i < 3; i++) {
        h[i] = grid[i][y];
    }

    for (auto s: h) {
        if (s == "X") {
            return true;
        }
    }

    int a = stoi(h[0]);
    int d = stoi(h[1]) - stoi(h[0]);
    
    if(stoi(h[1]) - d == a && stoi(h[2]) - (2 * d) == a){
        return true;
    } else {
        return false;
    }
}

bool verifyVertical(int x) {
    string v[3];

    for (int i = 0; i < 3; i++) {
        v[i] = grid[x][i];
    }

    for (auto s: v) {
        if (s == "X") {
            return true;
        }
    }

    int a = stoi(v[0]);
    int d = stoi(v[1]) - stoi(v[0]);
    
    if(stoi(v[1]) - d == a && stoi(v[2]) - (2 * d) == a){
        return true;
    } else {
        return false;
    }
}

void printGrid() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x< 3; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool gSolved = false;

bool checkSolved() {
    if(gSolved) return gSolved;
    bool isSolved = true;
    for (int x = 0; x < 3; x++) {
        for (string c: grid[x]) {
            if (c == "X") {
                isSolved = false;
                return isSolved;
            }
        }
    }

    if(isSolved) {
        printGrid();
    }

    gSolved = isSolved;
    return isSolved;
}

void solveCol(int x) {
    if(grid[0][x] != "X" && grid[1][x] != "X" && grid[2][x] != "X") {
        return;
    }

    if(grid[0][x] != "X" && grid[1][x] != "X") {
        int d = stoi(grid[1][x]) - stoi(grid[0][x]);
        grid[2][x] = to_string(stoi(grid[1][x]) + d);
        return;
    } else if(grid[1][x] != "X" && grid[2][x] != "X") {
        int d = stoi(grid[2][x]) - stoi(grid[1][x]);
        grid[0][x] = to_string(stoi(grid[1][x]) - d);
        return;
    } else if(grid[0][x] != "X" && grid[2][x] != "X") {
        int d = (stoi(grid[2][x]) - stoi(grid[0][x])) / 2;
        grid[1][x] = to_string(stoi(grid[0][x]) + d);
        return;
    }

}

void solveRow(int y) {
    if(grid[y][0] != "X" && grid[y][1] != "X" && grid[y][2] != "X") {
        return;
    }

    if(grid[y][0] != "X" && grid[y][1] != "X") {
        int d = stoi(grid[y][1]) - stoi(grid[y][0]);
        grid[y][2] = to_string(stoi(grid[y][1]) + d);
        return;
    } else if(grid[y][1] != "X" && grid[y][2] != "X") {
        int d = stoi(grid[y][2]) - stoi(grid[y][1]);
        grid[y][0] = to_string(stoi(grid[y][1]) - d);
        return;
    } else if(grid[y][0] != "X" && grid[y][2] != "X") {
        int d = (stoi(grid[y][2]) - stoi(grid[y][0])) / 2;
        grid[y][1] = to_string(stoi(grid[y][0]) + d);
        return;
    }

}


void solve() {
    if(checkSolved()) {
        return;
    }
    for (int y = 0; y < 3; y++) {
        if(checkSolved()) return;
        for (int x = 0; x < 3; x++) {
            if(checkSolved()) return;
            if(grid[x][y] == "X") {
                for (int n = -20; n <= 20; n++) {
                    if(checkSolved()) return;
                    grid[x][y] = to_string(n);

                    if(verifyHorizontal(y) && verifyVertical(x)) {
                        solve();
                    }

                    grid[x][y] = "X";
                }

                return;
            }
        }
    }
}

void solve7x() {
    if(XS >= 8) {
        string nonXValue = "0";
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if(grid[y][x] != "X") {
                    nonXValue = grid[y][x];
                }
            }
        }

        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                grid[y][x] = nonXValue ;
            }
        }

        return;
    }

    vector<vector<int>> nonXCoords;
    for(int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            if(grid[y][x] != "X") {
                nonXCoords.push_back({x, y});
            }
        }
    }

    if((nonXCoords[0][0] != nonXCoords[1][0] && nonXCoords[0][1] != nonXCoords[1][1]) || nonXCoords[0][0] == nonXCoords[1][0]) {
        for (int i = 0; i < 3; i++) {
            grid[nonXCoords[0][1]][i] = grid[nonXCoords[0][1]][nonXCoords[0][0]];
            grid[nonXCoords[1][1]][i] = grid[nonXCoords[1][1]][nonXCoords[1][0]];
        }
    } else if(nonXCoords[0][1] == nonXCoords[1][1]) {
        for (int i = 0; i < 3; i++) {
            grid[i][nonXCoords[0][0]] = grid[nonXCoords[0][1]][nonXCoords[0][0]];
            grid[i][nonXCoords[1][0]] = grid[nonXCoords[1][1]][nonXCoords[1][0]];
        }
    }

    for(int y = 0; y < 3; y++)  {
        solveRow(y);
    }

    for(int x = 0; x < 3; x++) {
        solveCol(x);
    }
}

void rowAndCol() {
    for(int y = 0; y < 3; y++)  {
        solveRow(y);
    }

    for(int x = 0; x < 3; x++) {
        solveCol(x);
    }

    bool isGap = false;

    for(int i = 0; i < 3; i++) {
        int rowX = 0;
        int colX = 0;
        for (int j = 0; j < 3; j++) {
            if(grid[i][j] == "X") {
                rowX++;
            }
            if(grid[j][i] == "X") {
                colX++;
            }
        }

        if(rowX == 1 || colX == 1) {
            isGap = true;
        }
    }

    if(isGap) {
        rowAndCol();
    }
}

void solve5x() {
    rowAndCol();
    if(checkSolved()) {
        return;
    }

    int xd = 0;
    
    for(int y = 0; y < 3; y++) {
        bool rowSolved = true;
        for(int x = 0; x < 3; x++) {
            if(grid[y][x] == "X") {
                rowSolved = false;
            }
        }

        if(rowSolved) {
            xd = stoi(grid[y][1]) - stoi(grid[y][0]);
        }
    }

    for(int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            if(grid[y][x] != "X") {
                if(x == 0) {
                    grid[y][1] = to_string(stoi(grid[y][0]) + xd);
                    grid[y][2] = to_string(stoi(grid[y][0]) + (2 * xd));
                } else if(x == 1) {
                    grid[y][2] = to_string(stoi(grid[y][1]) + xd);
                    grid[y][0] = to_string(stoi(grid[y][1]) - xd);
                } else if(x == 2) {
                    grid[y][1] = to_string(stoi(grid[y][2]) - xd);
                    grid[y][0] = to_string(stoi(grid[y][2]) - (2 * xd));
                }
            }
        }
    }

    rowAndCol();
    checkSolved();
}

int main() {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            string c;
            cin >> c;
            grid[x][y] = c;

            if(c == "X") {
                XS++;
            }
        }
    }

    int largestItem = 0;
    int smallestItem = 0;
    for(int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if(grid[y][x] != "X") {
                if(stoi(grid[y][x]) > largestItem) largestItem = stoi(grid[y][x]);
                if(stoi(grid[y][x]) < smallestItem) smallestItem = stoi(grid[y][x]);
            } 
        }
    }

    if(largestItem < 11 && smallestItem > -11) {
        solve();
        return 0;
    }

    if(XS >= 7) {
        solve7x();
        printGrid();
        return 0;
    } else if(XS == 5 || XS == 6) {
        solve5x();
        return 0;
    }

    rowAndCol();
    printGrid();

    // for(int y = 0; y < 3; y++)  {
    //     solveRow(y);
    // }

    // for(int x = 0; x < 3; x++) {
    //     solveCol(x);
    // }

    // solve();
}
