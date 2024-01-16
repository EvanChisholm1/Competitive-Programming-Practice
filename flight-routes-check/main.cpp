#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;
vector<int> adj[MAX_N][2];
bool vis[MAX_N];

void dfs(int s, bool back) {
    vis[s] = true;
    for(auto next: adj[s][back]) {
        if(!vis[next]) dfs(next, back);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(1, 1);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}
