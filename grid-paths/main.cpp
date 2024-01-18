#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long, long long>

using namespace std;

int main() {
    int n;
    cin >> n;

    ll dp[n][n];
    char grid[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
            char c;
            cin >> ws >> c;
            grid[i][j] = c;
        }
    }

    if(grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;
    queue<pii> q;
    q.push({0, 0});

    while(!q.empty()) {
        pii c = q.front();
        q.pop();

        vector<pii> next_locations;
        next_locations.push_back({c.first, c.second + 1});
        next_locations.push_back({c.first + 1, c.second});

        for(pii next: next_locations) {
            if(next.first >= n || next.second >= n) continue;
            if(grid[next.first][next.second] == '*') continue;

            if(dp[next.first][next.second] == 0) q.push(next);

            dp[next.first][next.second] += dp[c.first][c.second];
            dp[next.first][next.second] = dp[next.first][next.second] % ((ll) 1e9 + 7);
        }
    }

    cout << dp[n-1][n-1]  % ((long long) 1e9 + 7) << endl;
    return 0;
}
