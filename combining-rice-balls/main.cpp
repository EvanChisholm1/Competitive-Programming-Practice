#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    ll balls[100];

    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }

    ll dp[405][405];

    for(int i = 0; i < 405; i++) {
        for (int j = 0; j < 405; j++) {
            dp[i][j] = -1;
            if(i == j) dp[i][j] = balls[i];
        }
    }

    for(int size = 1; size <= n; size++) {
        // combine 2
        for(int start = 0; start < n - size; start++) {
            for(int mid = start; mid < n; mid++) {
                if(dp[start][mid] == -1 || dp[mid+1][start+size] == -1) continue;
                if(dp[start][mid] != dp[mid+1][start+size]) continue;

                dp[start][start+size] = max(dp[start][mid] + dp[mid + 1][start + size], dp[start][start+size]);
                break;
            }
        }

        if (size < 2) continue;

        for(int start = 0; start < n - size; start++) {
            for(int s2 = start; s2 < n; s2++) {
                for(int s3 = start; s3 < n; s3++) {
                    if(dp[start][s2] == -1 || dp[s2+1][s3] == -1 || dp[s3+1][start+size] == -1) continue;
                    if(dp[start][s2] != dp[s3+1][start+size]) continue;

                    dp[start][start+size] = max(dp[start][s2] + dp[s2+1][s3] + dp[s3+1][start+size], dp[start][start+size]);
                }
            }
        }
    }

    ll max_ball = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_ball = max(dp[i][j], max_ball);
        }
    }

    cout << max_ball << endl;
    return 0;
}
