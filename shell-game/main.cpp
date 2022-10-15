#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    int cups[3];
    for(int i = 0; i < 3; i++) cups[i] = i + 1;

    int scoreCount[3];
    memset(scoreCount, 0, sizeof(scoreCount));

    for (int i = 0; i < n; i++) {
        int ai, bi, g;
        cin >> ai >> bi >> g;

        int a = cups[ai - 1];
        int b = cups[bi - 1];
        cups[ai - 1] = b;
        cups[bi - 1] = a;

        scoreCount[cups[g - 1] - 1] += 1;
    }

    int maxScore = 0;
    for(int i = 0; i < 3; i++) {
        maxScore = max(scoreCount[i], maxScore);
    }

    cout << maxScore << endl;
}
