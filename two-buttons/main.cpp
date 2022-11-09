#include<bits/stdc++.h>

using namespace std;

int presses = 0;
int n, m;

void solve() {
    if(n == m) return;

    if(n <= round(round(float(m) / 2) / 2)) {
        n = n * 2;
        presses++;
    } else if(n - 1 == round(round(float(m) / 2) / 2)) {
        n--;
        presses++;
    } else if(m % 2 == 1 && n == round(float(m) / 2)) {
        n = n*2;
        presses++;
    } else if(n < m && n <= m / 2) {
        n = n*2;
        presses++;
    } else if(n > m / 2) {
        n--;
        presses++;
    }

    solve();
}

int main() {
    cin >> n >> m;

    solve();

    cout << presses << endl;
}

