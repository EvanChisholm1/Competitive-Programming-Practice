#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> measurements;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        measurements.push_back(m);
    }

    sort(measurements.begin(), measurements.end());

    vector<int> low;
    vector<int> high;

    int offset = round(n / 2.0);

    for (int i = 0; i < n; i++) {
        if(i < offset) {
            low.push_back(measurements[i]);
        } else {
            high.push_back(measurements[i]);
        }
    }

    reverse(low.begin(), low.end());

    for(int i = 0; i < low.size(); i++) {
        if(i == offset - 1 && n % 2 == 1) {
            cout << low[i] << " ";
            continue;
        }

        cout << low[i] << " " << high[i] << " ";
    }

    cout << endl;
}
