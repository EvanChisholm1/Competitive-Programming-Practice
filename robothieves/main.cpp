#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    int startingpos[2];
    char grid[n][m];

    vector<vector<int>> emptySpaces;

    for(int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            char c;
            cin >> c;
            grid[y][x] = c;

            if(c == *"S") {
                startingpos[0] = x;
                startingpos[1] = y;
            } else if(c == *".") {
                vector<int> space;
                space.push_back(x);
                space.push_back(y);
                emptySpaces.push_back(space);
            }
        }
    }

    

    queue<vector<int>> q;
    bool visited[n][m]{};
    int distance[n][m] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distance[i][j] = -1;
        }
    }

    visited[startingpos[1]][startingpos[0]] = true;
    distance[startingpos[1]][startingpos[0]] = 0;
    q.push({startingpos[0], startingpos[1]});

    while(!q.empty()) {
        vector<int> coords;
        coords.push_back(q.front()[0]);
        coords.push_back(q.front()[1]);
        q.pop();
        bool safe = true;
        for (int k = 0; k < coords[1]; k++) {
            int type = grid[k][coords[0]];
            if (type == *"C") {
                safe = false;
            } else if (type == *"W") {
                safe = true;
            }
        }
        if(safe == true) {
            for (int k = n; k > coords[1]; k--) {
                int type = grid[k][coords[0]];
                if (type == *"C") {
                    safe = false;
                } else if (type == *"W") {
                    safe = true;
                }
            }
        }
        if(safe == true) {
            for (int k = 0; k < coords[0]; k++) {
                int type = grid[coords[1]][k];
                if (type == *"C") {
                    safe = false;
                } else if (type == *"W") {
                    safe = true;
                }
            }
        }
        if(safe == true) {
            for (int k = m; k > coords[0]; k--) {
                int type = grid[coords[1]][k];
                if (type == *"C") {
                    safe = false;
                } else if (type == *"W") {
                    safe = true;
                }
            }
        }

        if(!safe) {
            continue;
        }


        int nextCoords[4][2] = {
            {coords[0] - 1, coords[1]},
            {coords[0] + 1, coords[1]},
            {coords[0], coords[1] + 1},
            {coords[0], coords[1] - 1},
        };

        for(int i = 0; i < 4; i++) {
            int next[2];
            next[0] = nextCoords[i][0];
            next[1] = nextCoords[i][1];

            if(visited[next[1]][next[0]]) {
                continue;
            }


            if (next[0] >= m || next[0] < 0) {
                continue;
            } else if (next[1] >= n || next[1] < 0) {
                continue;
            }

            visited[next[1]][next[0]] = true;

            char nextType = grid[next[1]][next[0]];
            if(nextType == *"W") {
                continue;
            } else if(nextType == *"C") {
                continue;
            } else if(nextType == *"U") {
                next[1] -= 1;
                if(visited[next[1]][next[0]]) {
                    continue;
                }
            } else if(nextType == *"D") {
                next[1] += 1;
                if(visited[next[1]][next[0]]) {
                    continue;
                }
            } else if(nextType == *"L") {
                next[0] -= 1;
                if(visited[next[1]][next[0]]) {
                    continue;
                }
            } else if(nextType == *"R") {
                next[0] += 1;
                if(visited[next[1]][next[0]]) {
                    continue;
                }
            }

            char nextNextType = grid[next[1]][next[0]];
            if(nextNextType == *"W") {
                continue;
            }

            visited[next[1]][next[0]] = true;

            // check for cameras
            bool safe = true;
            for (int k = 0; k < next[1]; k++) {
                int type = grid[k][next[0]];
                if (type == *"C") {
                    safe = false;
                } else if (type == *"W") {
                    safe = true;
                }
            }
            if(safe == true) {
                for (int k = n; k > next[1]; k--) {
                    int type = grid[k][next[0]];
                    if (type == *"C") {
                        safe = false;
                    } else if (type == *"W") {
                        safe = true;
                    }
                }
            }
            if(safe == true) {
                for (int k = 0; k < next[0]; k++) {
                    int type = grid[next[1]][k];
                    if (type == *"C") {
                        safe = false;
                    } else if (type == *"W") {
                        safe = true;
                    }
                }
            }
            if(safe == true) {
                for (int k = m; k > next[0]; k--) {
                    int type = grid[next[1]][k];
                    if (type == *"C") {
                        safe = false;
                    } else if (type == *"W") {
                        safe = true;
                    }
                }
            }

            if(safe == false) {
                continue;
            }

            distance[next[1]][next[0]] = distance[coords[1]][coords[0]] + 1;
            q.push({next[0], next[1]});
        }
    }

    int smallestdistance = 1000;

    for (int i = 0; i < emptySpaces.size(); i++) {
        int space[2];
        space[0] = emptySpaces[i][0];
        space[1] = emptySpaces[i][1];

        if(distance[space[1]][space[0]] > 0) {
            smallestdistance = min(smallestdistance, distance[space[1]][space[0]]);
        }

        cout << distance[space[1]][space[0]] << endl;
    }

    cout << smallestdistance << endl;
    return 0;
}
