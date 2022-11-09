#include<bits/stdc++.h>

using namespace std;

string grid[3][3];
int XS = 0;

void printGrid() {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x< 3; x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
    for(int y = 0; y < 3; y++)  {
        solveRow(y);
    }

    for(int x = 0; x < 3; x++) {
        solveCol(x);
    }
}

int main() {
    for (int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            string a;
            cin >> a;
            grid[y][x] = a;

            if(a == "X") {
                XS++;
            }
        }
    }

    solve();
    printGrid();
}
