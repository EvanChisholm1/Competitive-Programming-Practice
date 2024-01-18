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

    int dp[x + 1];
    for(int i = 0; i <= x; i++) {
        dp[i] = 0;
    }

    int max_pages = 0;

    for(int i = 0; i < n; i++) {
        for(int m = 0; m <= x; m++) {
            if(m - prices[i] < 0) continue;
            dp[m - prices[i]] = max(dp[m - prices[i]], dp[m] + pages[i]);
            max_pages = max(dp[m - prices[i]], max_pages);
        }
    }

    cout << max_pages << endl;

    return 0;
}
