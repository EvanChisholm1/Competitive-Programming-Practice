#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int n_even = 0;
    int n_odd = 0;
    
    int last_even = -1;
    int last_odd = -1;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c % 2 == 0) {
            last_even = i + 1;
            n_even++;
        } else {
            last_odd = i + 1;
            n_odd++;
        }
    }

    if(n_even == 1) {
        cout << last_even << endl;
    } else {
        cout << last_odd << endl;
    }
}
