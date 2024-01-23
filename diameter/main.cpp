#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2 * 1e5 + 10;

vector<int> g[MAX_N];

int max_dist = 0;
int farthest = 0;

void dfs(int x, int prev, int dist) {
    if(dist > max_dist) {
        farthest = x;
        max_dist = dist;
    }

    for(auto next: g[x]) {
        if(next == prev) continue;
        dfs(next, x, dist + 1);
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    int x = farthest;
    max_dist = 0;
    farthest = 0;

    dfs(x, 0, 0);
    cout << max_dist << endl;

    return 0;
}
