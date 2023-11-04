#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> towers;
    towers.push_back(INT32_MAX);

    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;

        if(towers[towers.size() - 1] <= s) {
            towers.push_back(s);
            continue;
        }

        int lo = 0;
        int hi = towers.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if(towers[mid] > s && towers[mid - 1] <= s) {
                towers[mid] = s;
                break;
            }

            if(s >= towers[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
    }

    cout << towers.size() << endl;
    return 0;
}
