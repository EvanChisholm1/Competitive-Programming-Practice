#include<bits/stdc++.h>

using namespace std;

int n;
int stones[100000];

int main() {
    cin >> n;
    int dp[n];

    for(int i = 0; i < n; i++) {
        cin >> stones[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for(int i = 0; i < n - 1; i++) {
        if(i + 1 < n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(stones[i] - stones[i + 1]));
        }
        if(i + 2 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(stones[i] - stones[i + 2]));
        }
    }

    cout << dp[n - 1] << endl;
}
