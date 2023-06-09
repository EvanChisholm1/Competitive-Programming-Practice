#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int d[n + 1];
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;

        d[i] = c;
    }

    int dp[n + 1][3];

    for(int i = 0; i < n + 1; i++) {
        dp[i][0] = 1000;
        dp[i][1] = 1000;
        dp[i][2] = 1000;
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 0; i < n; i++) {
        if(d[i] == 1 || d[i] == 3) {
            dp[i + 1][1] = min(dp[i][0], dp[i][2]);
        }
        if(d[i] == 2 || d[i] == 3) {
            dp[i + 1][2] = min(dp[i][0], dp[i][1]);
        }
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
        dp[i + 1][2] = min(dp[i + 1][2], dp[i][0] + 1);
        dp[i + 1][0] = min(dp[i + 1][0], min(dp[i][1] + 1, dp[i][2] + 1));
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;; 
}
