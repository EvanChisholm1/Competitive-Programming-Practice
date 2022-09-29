#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    bool restaurants[n];
    int phoRestaurants[m];

    for(int i = 0; i < n; i++) {
        restaurants[i] = false;
    }

    for(int i = 0; i < m; i++) {
        int r;
        cin >> r; 
        restaurants[r] = true;
        phoRestaurants[i] = r;
    }

    vector<int> graph[n];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    unordered_map<int, int> distances[n];

    for(int i = 0; i < n; i++) {
        if(!restaurants[i]) continue;

        bool visited[n];
        for (int k = 0; k < n; k++) {
            visited[k] = false;
        }
        int distance[n];
        queue<int> q;

        distance[i] = 0;
        visited[i] = true;
        q.push(i);
        while(!q.empty()) {
            int s = q.front();
            q.pop();

            if(restaurants[s]) {
                distances[i][s] = distance[s];
            }

            for(int j = 0; j < graph[s].size(); j++) {
                int next = graph[s][j];

                if(visited[next]) continue;
                visited[next] = true;
                distance[next] = distance[s] + 1;
                q.push(next);
            }
        }
    }

    int shortest = int(INFINITY);

    do {
        int distance = 0;
        for (int i = 0; i < m - 1; i++) {
            distance += distances[phoRestaurants[i]][phoRestaurants[i+1]];
        }
        shortest = min(shortest, distance);
    } while (next_permutation(phoRestaurants, phoRestaurants + m));

    cout << shortest << endl;
}
