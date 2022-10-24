#include<bits/stdc++.h>

using namespace std;

int requiredDistance, n;

int solve(int maxSpeed) {
    int currentDistance = 0;
    int time = 0;

    int slowDownDistance = 0;

    for(int currentSpeed = 1; ; currentSpeed++) {
        currentDistance += currentSpeed;
        time++;

        if(currentDistance + slowDownDistance >= requiredDistance) {
            return time;
        }

        if(currentSpeed >= maxSpeed) {
            slowDownDistance += currentSpeed;
            time++;

            if(currentDistance + slowDownDistance >= requiredDistance) {
                return time;
            }
        }
    }
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> requiredDistance >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
}
