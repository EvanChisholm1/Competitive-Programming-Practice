#include<bits/stdc++.h>

using namespace std;

vector<int> tree[200001];
bool visited[200001];
int subList[200001];

int dfs(int s) {
    int subordinates = 0;

    for(auto next: tree[s]) {
        if(visited[next]) continue;
        visited[next] = true;
        subordinates += dfs(next) + 1;
    }

    subList[s] = subordinates;
    return subordinates;
}

int main() {
    int n;
    cin >> n;

    for(int i = 2; i < n + 1; i++) {
        int e;
        cin >> e;
        tree[e].push_back(i);
    }

    memset(visited, false, sizeof(visited));

    dfs(1);

    for(int i = 1; i < n + 1; i++) {
        cout << subList[i] << " ";
    }

    cout << endl;
    return 0;
}
