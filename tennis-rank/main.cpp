#include<bits/stdc++.h>

using namespace std;

vector<int> g[21];
bool isCyclic[21];
bool visited[21] = {false};

void dfs(int starting, int s, bool firstRun) {
    if(s == starting && !firstRun) isCyclic[s] = true;
    if(visited[s] && !firstRun) return;
    visited[s] = true;

    for(auto next: g[s]) {
        dfs(starting, next, false);
    }
}

int main() {
    int n, k;
    cin >> n >> k;


    for(int i = 0; i < k; i++) {
        int a, b, aScore, bScore;
        cin >> a >> b >> aScore >> bScore;

        if(aScore > bScore) {
            g[a].push_back(b);
        } else {
            g[b].push_back(a);
        }
    }

    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, i, true);
    }

    int cyclicPlayers = 0;
    for(auto x: isCyclic) {
        if(x) cyclicPlayers++;
    }

    cout << cyclicPlayers << endl;
}
