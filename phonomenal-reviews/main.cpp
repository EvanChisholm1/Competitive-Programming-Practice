// TODO: Comment this to expand my learning
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

bool use[MAX];
int depth[MAX];
vector<int> graph[MAX];
int m, n, node, mini, nodes;

void prune(int s, int p) {
    for(auto x: graph[s]) {
        if(x == p) {
            continue;
        }

        prune(x, s);
        use[s] |= use[x];
    }
}


void findFarthest(int s, int p) {
    nodes++;

    for (auto x: graph[s]) {
        if(x == p || !use[x]) continue;
        depth[x] = depth[s] + 1;

        if(depth[x] > mini) {
            mini = depth[s];
            node = x;
        }
        findFarthest(x, s);
    }
}

int main() {
    cin >> n >> m;
    int root;

    for(int i = 0; i < m; i++) {
        int r;
        cin >> r; 
        use[r] = true;
        root = r;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    prune(root, -1);
    findFarthest(root, -1);

    mini = 0;
    nodes = 0;

    memset(depth, 0, sizeof(depth));
    findFarthest(node, -1);

    int result = 2 * (nodes - 1) - depth[node];
    cout << result << endl;
}