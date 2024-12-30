#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n+10];

    for(int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    ll max_so_far = a[0];
    bool is_pos = a[0] > 0;

    for(int i = 0; i < n; i++) {
        if(a[i] > 0 != is_pos) {
            is_pos = !is_pos;
            sum += max_so_far;
            max_so_far = a[i];
        }

        max_so_far = max(max_so_far, a[i]);
    }

    sum += max_so_far;

    cout << sum << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
    return 0;
}
