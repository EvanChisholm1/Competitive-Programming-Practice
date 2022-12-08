#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> g[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool visited[n + 1];
    int distance[n + 1];
    int previous[n + 1];

    memset(visited, false, sizeof(visited));
    memset(distance, -1, sizeof(distance));
    queue<int> q;

    q.push(n);
    distance[n] = 1;
    visited[n] = true;
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        if(s == 1) break;

        for(auto next: g[s]) {
            if(visited[next]) continue;
            visited[next] = true;
            distance[next] = distance[s] + 1;
            previous[next] = s;
            q.push(next);
        }
    }

    if(visited[1]) {
        cout << distance[1] << endl;
        int current = 1;
        while (current != n) {
            cout << current << " ";
            current = previous[current];
        }

        cout << n << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
