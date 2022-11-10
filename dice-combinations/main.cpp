#include<bits/stdc++.h>

using namespace std;

long long dp[1000001];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for (int x = 1; x <= 6; x++) {
            if(i - x < 0) break;
            dp[i] += dp[i - x];
        }
        dp[i] %= 1000000007;
    }

    cout << dp[n] << endl;
    return 0;
}