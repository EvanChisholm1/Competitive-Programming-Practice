#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, ll>> adj[n + 1];
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e15));
    for(int i = 1; i <= n; i++) {
        for(auto x: adj[i]) {
            dist[i][x.first] = min(dist[i][x.first], x.second);
        }
        dist[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == 1e15) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }

    return 0;
}
