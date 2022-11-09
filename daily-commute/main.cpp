#include<bits/stdc++.h>

using namespace std;

vector<int> order;
int n, w, d;

int solve(vector<int> g[]) {
    bool visited[n + 1];
    int distance[n + 1];

    memset(visited, false, sizeof(visited));
    memset(distance, 0, sizeof(distance));

    queue<int> q;

    q.push(order[0]);

    distance[order[0]] = 0;
    visited[order[0]] = true;

    while(!q.empty()) {
        int s = q.front();
        q.pop();

        // cout << "CURRENT S: " << s << endl;

        if(s == n) {
            // cout << "DISTANCE OF: " << s << ": " << distance[s] << endl;
            return distance[s];
        }

        vector<int> paths;
        for(auto p: g[s]) {
            paths.push_back(p);
        }
        for(int i = 0; i < order.size(); i++) {
            if(order[i] == s) {
                paths.push_back(order[i + 1]);
            }
        }

        for(auto path: paths) {
            // cout << "PATH: " << path << endl;
            if(visited[path]) {
                continue;
            }
            visited[path] = true;
            distance[path] = distance[s] + 1;
            q.push(path);
        }
    }

    return 0;
}

int main() {
    cin >> n >> w >> d;

    vector<int> g[n + 1];
    for(int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        order.push_back(a);
    }

    vector<int> distances;

    for(int i = 0; i < d; i++) {
        int aIndex, bIndex;
        cin >> aIndex >> bIndex;

        int a = order[aIndex - 1];
        int b = order[bIndex - 1];

        order[bIndex - 1] = a;
        order[aIndex - 1] = b;


        // cout << endl << "NEW DAY " << endl<< endl << endl;

        // for(auto x: order) {
        //     cout << x << " ";
        // }

        // cout << endl;
        // cout << endl;

        distances.push_back(solve(g));
        // cout << solve(g) << endl;
    }

    for(auto x: distances) {
        cout << x << endl;
    }

    return 0;
}
