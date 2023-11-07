#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // weighted adj list
    vector<pair<int, int>> g[n+1];

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }


    // create distance array and set all values to infinity
    ll dist[n + 1];
    for(int i = 0; i < n + 1; i++) {
        dist[i] = INFINITY;
    }

    // create visited array and  set all values to false by default
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    // set the distance of the starting item to 0
    dist[1] = 0;


    // create priority queue for the search, first value being the distance and second value being the index
    priority_queue<pair<ll, ll>> q;
    // push the first item to the queue
    q.push({0, 1});

    // loop until all items have been processed
    while(!q.empty()) {
        // the index of the node being processed
        ll a = q.top().second;
        q.pop();

        // if the node has been processed then skip
        if(visited[a]) continue;
        visited[a] = true;

        // add vertices to the queue
        for(auto next: g[a]) {
            int b = next.first;
            int w = next.second;
            
            // only process node if it decreases the distance
            if(dist[b] > dist[a] + w) {
                // essentially use a as a middle man for b
                dist[b] = dist[a] + w;
                // add to queue for processing
                q.push({-dist[b], b});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    cout << endl;
    return 0;
}
