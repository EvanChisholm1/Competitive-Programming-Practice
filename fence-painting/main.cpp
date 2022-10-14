#include<bits/stdc++.h>

using namespace std;

bool isPainted[101] = {false};

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = a; i < b; i++) {
        isPainted[i] = true;
    }

    for (int i = c; i < d; i++) {
        isPainted[i] = true;
    }

    int painted = 0;
    for(int i = 0; i < 101; i++){
        if(isPainted[i]) painted++;
    }
    cout << painted << endl;
}
