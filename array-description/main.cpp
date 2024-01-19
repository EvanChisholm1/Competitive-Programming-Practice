#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    if(a[0] != 0) {
        dp[0][a[0]] = 1;
    } else {
        for(int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(a[i] != 0 && a[i + 1] != 0) {
            if(abs(a[i] - a[i + 1]) > 1) continue;
            dp[i + 1][a[i + 1]] = dp[i][a[i]];
        } else if(a[i] != 0) {
            vector<int> potential_next = {a[i] - 1, a[i], a[i] + 1};

            for(auto next: potential_next) {
                if(next > m || next < 1) continue;
                dp[i + 1][next] += dp[i][a[i]];
                dp[i + 1][next] = dp[i + 1][next] % ((ll) 1e9 + 7);
            }
        } else {
            for(int j = 1; j <= m; j++) {
                vector<int> potential_next = {j - 1, j, j + 1};

                for(auto next: potential_next) {
                    if(next > m || next < 1) continue;
                    dp[i + 1][next] += dp[i][j];
                    dp[i + 1][next] = dp[i + 1][next] % ((ll) 1e9 + 7);
                }
            }
        }
    }

    if(a[n-1] != 0) {
        cout << dp[n-1][a[n-1]] << endl;
    } else {
        ll sum = 0;
        for(int i = 1; i <= m; i++) {
            sum += dp[n-1][i];
            sum = sum % ((ll) 1e9 + 7);
        }
        cout << sum << endl;
    }
}
