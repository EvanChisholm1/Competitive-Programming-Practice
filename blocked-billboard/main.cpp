#include<bits/stdc++.h>

using namespace std;

int findAreaOfIntersection(int r1[4], int r2[4]) {
    int w = min(r1[2], r2[2]) - max(r1[0], r2[0]);
    int h = min(r1[3], r2[3]) - max(r1[1], r2[1]);

    if(w < 0 || h < 0) return 0;

    return w * h;
}
int findRectArea(int r[4]) {
    int w = r[2] - r[0];
    int h = r[3] - r[1];
    return w * h;
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int b1[4];
    int b2[4];
    int truck[4];

    cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];
    cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];
    cin >> truck[0] >> truck[1] >> truck[2] >> truck[3];

    int a1 = findRectArea(b1) - findAreaOfIntersection(b1, truck);
    int a2 = findRectArea(b2) - findAreaOfIntersection(b2, truck);
    cout << a1 + a2 << endl;
}
