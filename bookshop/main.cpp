#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> prices = vector<int>(n, 0);
    vector<int> pages = vector<int>(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<int> dp = vector<int>(x + 1, 0);
    dp[0] = 0;

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < n; j++) {
            if(i + prices[j] <= x) {
                dp[i + prices[j]] = max(dp[i + prices[j]], dp[i] + pages[j]);
            }
        }
    }

    cout << dp[x - 1] << endl;
}
