#include<bits/stdc++.h>

using namespace std;

const int MAX = 100001;
vector<int> cows[MAX];
pair<int, int> coords[MAX];
bool visited[MAX];

int maxX = 0;
int maxY = 0;

int minX = INT_MAX;
int minY = INT_MAX;

void dfs(int s) {
    visited[s] = true;

    maxX = max(maxX, coords[s].first);
    maxY = max(maxY, coords[s].second);

    minX = min(minX, coords[s].first);
    minY = min(minY, coords[s].second);

    for(int next: cows[s]) {
        if (visited[next]) continue;
        dfs(next);
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i < n + 1; i++) {
        pair<int, int> coord;
        cin >> coord.first >> coord.second;
        coords[i] = coord;
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cows[a].push_back(b);
        cows[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    
    int minPerim = INT_MAX;

    for(int i = 1; i < n + 1; i++) {
        if(visited[i]) continue;

        maxX = 0;
        maxY = 0;

        minX = INT_MAX;
        minY = INT_MAX;

        dfs(i);

        int currentPerimeter = ((maxX - minX) + (maxY - minY)) * 2;
        minPerim = min(minPerim, currentPerimeter);
    }

    cout << minPerim << endl;
    return 0;
}
