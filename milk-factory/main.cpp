#include<bits/stdc++.h>

using namespace std;

const int MAX = 101;
int visited[MAX];

int allVisited[MAX];

vector<int> g[MAX];

void dfs(int a) {
    visited[a] = true;

    for(int i = 0; i < g[a].size(); i++) {
        dfs(g[a][i]);
    }
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    memset(allVisited, true, sizeof(allVisited));

    for(int i = 1; i < n + 1; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i);

        for(int j = 0; j < MAX; j++) {
            if(!visited[j]) allVisited[j] = false;
        }
    }

    for(int i = 0; i < MAX; i++) {
        if(allVisited[i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
