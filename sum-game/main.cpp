#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll ags[n];
    ll bgs[n];

    for(int i = 0; i < n; i++) {
        cin >> ags[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> bgs[i];
    }

    ll a = 0;
    ll b = 0;

    ll k = 0;

    for(int i = 0; i < n; i++) {
        a += ags[i];
        b += bgs[i];

        if(a == b) k = i + 1;
    }

    cout << k << endl;
    return 0;
}

