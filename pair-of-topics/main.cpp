#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    ll a[n];
    ll b[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<ll> diff(n, 0);

    for(int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    sort(diff.begin(), diff.end());

    ll total = 0;

    for(int i = 0; i < n - 1; i++) {
        int lo = i + 1;
        int hi = n;
        int mid;

        if(diff[i] + diff[n - 1] <= 0) continue;

        while(lo < hi) {
            mid = (lo + hi) / 2;

            if(diff[mid] + diff[i] <= 0) {
                lo = mid;
            } else if(diff[mid - 1] + diff[i] <= 0) {
                break;
            } else {
                hi = mid;
            }
        }

        total += n - mid;
    }


    cout << total << endl;
    return 0;
}
