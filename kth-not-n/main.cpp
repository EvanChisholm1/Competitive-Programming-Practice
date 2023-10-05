#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll high = n * k;
    ll low = 0;
    while(high != low) {
        ll mid = (high + low) / 2;
        if (mid % n == 0) mid++;
        
        ll index = mid - (mid / n);

        if (index == k) {
            cout << mid << endl;
            return;
        }

        if(index > k) high = mid;
        if(index < k) low = mid;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}