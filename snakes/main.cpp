#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    // dp over every group and and the number of changes
    ll dp[n + 10][k + 10];

    // get input
    int sn[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> sn[i];
    }

    // set the values maxed out
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = 1e9;
        }
    }


    // largest variable and total space used variable
    int largest = -1;
    int total_space_used = 0;
    for(int i = 1; i <= n; i++) {
        // update the largest variable to the current if it is bigger
        largest = max(largest, sn[i]);
        // dp at location i with 0 changes has to be the size of the largest snake * the current location
        dp[i][0] = largest * i;

        // loop every change value
        for(int j = 1; j <= k; j++) {
            // set the net size to the current
            int net_size = sn[i];
            // for every value before i loop
            for(int c = i - 1; c >= 0; c--) {
                // update dp[i][j]
                // starting at c and a change value one greater
                // decrease dp[i][j] if it is smaller
                dp[i][j] = min(dp[i][j], dp[c][j - 1] + net_size * (i - c));
                // set the netsize to the max of the interval between i and c
                net_size = max(net_size, sn[c]);
            }
        }
        total_space_used += sn[i];
    }

    cout << dp[n][k] - total_space_used << endl;
    return 0;
}
