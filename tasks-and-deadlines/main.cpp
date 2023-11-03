#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks;
    for(int i = 0; i < n; i++) {
        pair<int, int> t;

        cin >> t.first >> t.second;
        tasks.push_back(t);
    }

    sort(tasks.begin(), tasks.end());

    long long current_time = 0;
    long long reward = 0;
    for(auto t: tasks) {
        current_time += t.first;
        reward += t.second - current_time;
    }

    cout << reward << endl;
    return 0;
}
