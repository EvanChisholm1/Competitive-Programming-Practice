#include<bits/stdc++.h>

using namespace std;

vector<int> coins;
int main() {
    int n, x;
    cin >> n >> x;


    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    vector<long long> dp = vector<long long> (x + 1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int x: coins) {
            if(i - x >= 0) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
    }

    if(dp[x] == INT_MAX) {
        cout << "-1" << endl;
        return 0;
    }

    cout << dp[x] << endl;
    return 0;
}
