#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    vector<pair<int, int>> rev[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        rev[b].push_back({a, c});
    }

    ll dista[n + 1];
    ll distb[n + 1];
    for(int i = 0; i <= n; i++) {
        dista[i] = 1e15;
        distb[i] = 1e15;
    }

    dista[1] = 0;
    distb[n] = 0;

    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    priority_queue<pair<ll, int>> q;
    q.push({0, 1});

    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if(visited[a]) continue;
        visited[a] = true;

        for(auto next: adj[a]) {
            int b = next.first;
            int w = next.second;

            if(dista[a] + w < dista[b]) {
                dista[b] = dista[a] + w;
                q.push({-dista[b], b});
            }
        }
    }

    memset(visited, false, sizeof(visited));
    priority_queue<pair<ll, int>> qb;
    qb.push({0, n});

    while(!qb.empty()) {
        int a = qb.top().second;
        qb.pop();
        if(visited[a]) continue;
        visited[a] = true;

        for(auto next: rev[a]) {
            int b = next.first;
            int w = next.second;

            if(distb[a] + w < distb[b]) {
                distb[b] = distb[a] + w;
                qb.push({-distb[b], b});
            }
        }
    }

    ll min_flight = 1e15;

    for (int i = 1; i <= n; i++) {
        for(auto f: adj[i]) {
            min_flight = min(min_flight, dista[i] + ((ll) f.second / 2) + distb[f.first]);
        }
    }

    cout << min_flight << endl;

    return 0;
}

