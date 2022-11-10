#include<bits/stdc++.h>

using namespace std;

int earn[1001];

vector<int> g[1001];

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        cin >> earn[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    vector<vector<int>> dp(1000, vector<int>(n, -1));
    dp[0][0] = 0;
    int maxEarnings = 0;

    for(int d = 0; d < 1000 - 1; d++) {
        for(int i = 0; i < n; i++) {
            if(dp[d][i] == -1) continue;
            for(int next: g[i]) {
                dp[d + 1][next] = max(dp[d + 1][next], dp[d][i] + earn[next]);
            }
        }

        maxEarnings = max(maxEarnings, dp[d][0] - (c * (d * d)));
    }

    cout << maxEarnings << endl;

    return 0;
}