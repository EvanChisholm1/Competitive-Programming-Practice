#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int coins[n];
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins[i] = c;
    }

    long long dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - coins[j] < 0) continue;
            dp[i] += dp[i - coins[j]];
        }
        dp[i] %= 1000000007;
    }


    cout << dp[x] << endl;

    return 0;
}
