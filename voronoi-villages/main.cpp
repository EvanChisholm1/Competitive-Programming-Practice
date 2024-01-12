#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<ll> vs;

    for(int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        vs.push_back(v);
    }

    sort(vs.begin(), vs.end());

    vector<double> ns;

    for(int i = 0; i < n - 1; i++) {
        ns.push_back(((double)vs[i] + (double)vs[i + 1]) / (double)2.0);
    }

    double min_dist = 1e9;

    for(int i = 0; i < ns.size() - 1; i++) {
        min_dist = min(min_dist, ns[i+1] - ns[i]);
    }

    printf("%.1f\n", min_dist);

    // round
    // cout << min_dist << endl;

    // for(auto n:ns) cout << n << " ";
    // cout << endl;

    return 0;
}

