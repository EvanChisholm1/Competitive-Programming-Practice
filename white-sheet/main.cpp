#include<bits/stdc++.h>

using namespace std;

long long findIntersectionArea(long long r1[4], long long r2[4]) {
    long long w = min(r1[2], r2[2]) - max(r1[0], r2[0]);
    long long h = min(r1[3], r2[3]) - max(r1[1], r2[1]);

    if(w < 0 || h < 0) return 0;
    return w * h;
}

long long findArea(long long  r[4]) {
    long long w = r[2] - r[0];
    long long  h = r[3] - r[1];

    return w * h;
}

int main() {
    long long whiteSheet[4];
    long long b1[4];
    long long b2[4];

    cin >> whiteSheet[0] >> whiteSheet[1] >> whiteSheet[2] >> whiteSheet[3];
    cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];
    cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];

    if(b1[0] < whiteSheet[0]) {
        b1[0] = whiteSheet[0];
    }
    if(b1[1] < whiteSheet[1]) {
        b1[1] = whiteSheet[1];
    }
    if(b1[2] > whiteSheet[2]) {
        b1[2] = whiteSheet[2];
    }
    if(b1[3] > whiteSheet[3]) {
        b1[3] = whiteSheet[3];
    }

    long long blacksheetIntersection = findIntersectionArea(b1, b2);

    long long wArea = findArea(whiteSheet);
    long long ia1 = findIntersectionArea(whiteSheet, b1);
    long long ia2 = findIntersectionArea(whiteSheet, b2);
    if(wArea - (ia1 + ia2) + blacksheetIntersection <= 0) { 
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
        return 0;
    }
}
