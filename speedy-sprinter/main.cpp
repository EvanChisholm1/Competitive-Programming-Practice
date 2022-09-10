#include<bits/stdc++.h>

using namespace std;

struct obs {
    int t;
    float x;
    bool operator<(const obs &o) {
        if(t < o.t) return true;
        else return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<obs> observations;

    for (int i = 0; i < n; i++) {
        int t;
        float x;
        cin >> t >> x;
        
        obs current;
        current.t = t;
        current.x = x;

        observations.push_back(current);
    }

    sort(observations.begin(), observations.end());

    float max_speed = 0.0;

    for(int i = 1; i < observations.size(); i++) {
        obs previous_o = observations.at(i - 1);
        obs current_o = observations.at(i);

        float speed = abs((current_o.x - previous_o.x) / (current_o.t - previous_o.t));

        if(speed > max_speed) max_speed = speed;
    }

    cout << max_speed << endl;

    return 0;
}
