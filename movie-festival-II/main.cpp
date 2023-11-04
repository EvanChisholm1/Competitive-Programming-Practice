#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);

    for(int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    multiset<int> people_times;
    for(int i = 0; i < k; i++) {
        people_times.insert(0);
    }

    int total = 0;

    for(auto m: movies) {
        auto l = people_times.upper_bound(m.second);

        if(l == begin(people_times)) continue;
        total++;

        people_times.erase(--l);
        people_times.insert(m.first);
    }
    cout << total << endl;
}

