#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> first(8, -1);

    int longest = 0;
    int current_r = 0;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        current_r = (current_r + c) % 7;

        if(first[current_r] == -1) {
            first[current_r] = i;
        } else {
            longest = max(longest, i - first[current_r]);
        }
    }

    cout << longest << endl;
    return 0;
}
