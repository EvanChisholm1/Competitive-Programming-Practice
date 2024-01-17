#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int s[n];

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(n, -1);

    for(int i = 0; i < n; i++) {
        int current = s[i];

        for(int j = i; j > i - k && j >= 0; j--) {
            current = max(current, s[j]);

            if(j > 1) {
                dp[i] = max(dp[i], dp[j - 1] + current * (i - j + 1));
            } else {
                dp[i] = max(dp[i], current * (i - j + 1));
            }
        }
    }

    cout << dp[n -1] << endl;
    return 0;
}
