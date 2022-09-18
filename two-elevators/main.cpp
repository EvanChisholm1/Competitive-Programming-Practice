#include<bits/stdc++.h>

using namespace std;

int fastestElevator(int a, int b, int c) {
    int aTime = a - 1;
    int bTime = abs(b - c) + c - 1;

    if(aTime < bTime) {
        return 1;
    } else if (bTime < aTime) {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << fastestElevator(a, b, c) << endl;
    }

    return 0;
}
