#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(1001, 0);

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        r[c]++;
    }

    int largest_freq = 0;
    int largest_freq_occurences = 0;

    int second_freq = 0;
    int second_freq_occurences = 0;

    for(int i = 0; i < r.size(); i++) {
        if(r[i] > largest_freq) {
            second_freq = largest_freq;
            second_freq_occurences = largest_freq_occurences;

            largest_freq = r[i];
            largest_freq_occurences = 1;
        } else if (r[i] == largest_freq) {
            largest_freq_occurences++;
        } else if (r[i] > second_freq) {
            second_freq = r[i];
            second_freq_occurences = 1;
        } else if (r[i] == second_freq) {
            second_freq_occurences++;
        }
    }

    int largest_diff = 0;

    for(int i = 0; i < r.size(); i++) {
        if(r[i] != largest_freq) continue;
        for(int k = 0; k < r.size(); k++) {
            if(r[i] == 0 || r[k] == 0) continue;
            if(largest_freq_occurences > 1 && r[k] != largest_freq) continue;
            if((r[k] == largest_freq || r[k] == second_freq) && abs(k - i) > largest_diff) {
                largest_diff = abs(k - i);
            }
        }
    }

    cout << largest_diff << endl;

    return 0;
}
