#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int books[n];

    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int a = 0;
    int b = 0;

    int maxBooks = 0;
    int current = 0;
    while(a < n && b < n) {
        while (b < n) {
            current += books[b];
            b++;

            if(current > t) {
                b--;
                current -= books[b];
                break;
            }
        }

        maxBooks = max(maxBooks, b - a);
        current -= books[a];
        a++;
    }

    cout << maxBooks << endl;
}
