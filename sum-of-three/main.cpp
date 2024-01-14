#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> a;

    for(int i = 0; i < n; i++) {
        ll c;
        cin >> c;

        a.push_back({c, i + 1});
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        int lhs = 0;
        int rhs = a.size() - 1;

        while(lhs < rhs) {
            if(lhs == i) {
                lhs++;
                continue;
            }
            if(rhs == i) {
                rhs--;
                continue;
            }

            ll sum = a[i].first + a[lhs].first + a[rhs].first;
            if(sum < x) lhs++;
            if(sum > x) rhs--;
            if(sum == x) {
                cout << a[i].second << " " << a[lhs].second << " " << a[rhs].second << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
