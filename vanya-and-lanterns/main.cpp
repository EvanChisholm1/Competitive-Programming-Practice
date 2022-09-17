#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> lanterns;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        lanterns.push_back(a);
    }


    sort(lanterns.begin(), lanterns.end());

    double ans = max(double(lanterns[0] * 2), double((l - lanterns[n - 1]) * 2));

    for(int i = 1; i < n; i++) {
        double a = double(lanterns[i - 1]);
        double b = double(lanterns[i]);

        ans = max(ans, b - a);
    }

    printf("%.9f\n", ans / 2);
}
