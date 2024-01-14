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

    // two pointer algorithim
    // other possible solution is to use a map
    // map is likely faster? but I'm practicing two pointer algos.
    int lhs = 0;
    int rhs = a.size() - 1;
    while (lhs < rhs) {
        int sum = a[lhs].first + a[rhs].first;
        if(sum > x) rhs--;
        else if(sum < x) lhs++;
        else if (sum == x) break;
    }

    if(lhs == rhs) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << a[lhs].second << " " << a[rhs].second << endl;

    return 0;
}
