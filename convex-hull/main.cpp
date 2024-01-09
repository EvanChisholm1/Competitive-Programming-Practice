#include<bits/stdc++.h>
#define rt struct Route
#define qi struct Queue_Item
#define ll long long

struct Route {
    ll to;
    ll t;
    ll h;
};

using namespace std;

int main() {
    int k, n, m, start, end;
    cin >> k >> n >> m;

    vector<rt> g[n+1];
    for (int i = 0; i < m; i++) {
        ll a, b, t, h;
        cin >> a >> b >> t >> h;
        g[a].push_back({b, t, h});
        g[b].push_back({a, t, h});
    }

    cin >> start >> end;

    // distance list of k * n
    ll dist[k+1][n+1];
    // memset(dist, 1e9, sizeof(ll) * (k+1) * (n+1));
    // vistited list of k * n
    bool visited[k+1][n+1];
    // memset(visited, false, sizeof(bool) * (k+1) * (n+1));
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            dist[i][j] = INT64_MAX;
            visited[i][j] = false;
        }
    }

    dist[k][start] = 0;
    // skip if visited[h][t] is true
    // for each connected node update dist[new_h][new_t] if t is lower than previous t

    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push({0, {start, k}});

    while(!q.empty()) {
        ll a = q.top().second.first;
        ll h = q.top().second.second;
        // cout << "at " << a << " with thickness " << h << endl;

        q.pop();

        if(visited[h][a]) continue;
        visited[h][a] = true;

        for(auto next: g[a]) {
            ll b = next.to;
            ll t = next.t;
            ll damage = next.h;

            if(h - damage <= 0) continue;
            // cout << a << " is connected to " << b << endl;

            if(dist[h-damage][b] > dist[h][a] + t) {
                dist[h-damage][b] = dist[h][a] + t;
                q.push({-dist[h-damage][b], {b, h-damage}});
            }
        }
    }

    ll min_dist = INT64_MAX;
    for(int i = 0; i <= k; i++) {
        min_dist = min(min_dist, dist[i][end]);
    }

    if(min_dist == INT64_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_dist << endl;
    }

    return 0;
}
