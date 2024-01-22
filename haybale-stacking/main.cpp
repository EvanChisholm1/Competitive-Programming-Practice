#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> starts;
    vector<int> ends;

    for(int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        starts.push_back(s);
        ends.push_back(e);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    vector<int> h(n, 0);

    int start_pointer = 0;
    int end_pointer = 0;
    int current_add = 0;
    for(int i = 0; i < n; i++) {
        while(start_pointer < starts.size() && starts[start_pointer] - 1 == i) {
            current_add++;
            start_pointer++;
        }

        h[i] += current_add;

        while(end_pointer < ends.size() && ends[end_pointer] - 1 == i) {
            current_add--;
            end_pointer++;
        }
    }

    sort(h.begin(), h.end());

    cout << h[h.size() / 2] << endl;

    return 0;
}
