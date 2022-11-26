#include<bits/stdc++.h>

using namespace std;

const int MOD = int (1e9) + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    vector<int> dp = vector<int>(x + 1, 0);
    dp[0] = 1;

    for(auto i: coins) {
        for(int j = 1; j <= x; j++) {
            if(j - i < 0) continue;
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}
