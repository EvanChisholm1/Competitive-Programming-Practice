#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll longest_b = 0;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        longest_b = max(longest_b, temp);
        sum += temp;
    }

    cout << max(longest_b * 2, sum) << endl;
}
