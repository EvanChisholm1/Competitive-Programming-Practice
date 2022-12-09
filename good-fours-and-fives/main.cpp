#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[5] = 1;

    for(int i = 5; i < n + 1; i++) {
        dp[i] += dp[i-5];
    }

    dp[4] = 1;
    for(int i = 5; i < n + 1; i++) {
        dp[i] += dp[i-4];
    }

    cout << dp[n] << endl;
    return 0;
}
