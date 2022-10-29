#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int x[200];
int y[200];
int p[200];
bool visited[200];
int n;

vector<ll> g[200];

int cows = 0;
void dfs(int s) {
    visited[s] = true;
    cows++;
    for(auto x: g[s]) {
        if(visited[x]) continue;
        visited[x] = true;
        dfs(x);
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }


    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sumDist = (x[i] - x[j]) * (x[i] - x[j])
						  + (y[i] - y[j]) * (y[i] - y[j]);
			int hip = p[i] * p[i];
			if (sumDist <= hip) {
                g[i].push_back(j);
            } 
		}
	}

    int maxReach = 0;
    for(int i = 0; i < n; i++) {
        cows = 0;
        memset(visited, false, sizeof(visited));
        dfs(i);
        
        maxReach = max(maxReach, cows);
    }

    cout << maxReach << endl;
}
