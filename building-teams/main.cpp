#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e5;

int teams[MAX+1];
vector<int> g[MAX+1];

bool dfs(int s, int t) {
    teams[s] = t;
    for(auto next: g[s]) {
        if(teams[next] == teams[s]) return false;
        if(teams[next] != -1) continue;

        int next_team;
        if(t == 1) next_team = 2;
        else next_team = 1;

        bool is_valid = dfs(next, next_team);
        if(!is_valid) return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;


    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        teams[i] = -1;
    }


    bool is_possible = true;
    for(int i = 1; i <= n; i++) {
        if(teams[i] == -1) {
            bool valid = dfs(i, 1);
            if(!valid) {
                is_possible = false;
                break;
            }
        }
    }

    if(!is_possible) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        if(teams[i] == -1) cout << 1 << " ";
        else cout << teams[i] << " ";
    }

    cout << endl;

    return 0;
}
