#include<bits/stdc++.h>

using namespace std;

void solve(string s) {
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}
