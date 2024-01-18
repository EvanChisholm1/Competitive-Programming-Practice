#include<bits/stdc++.h>

using namespace std;

vector<int> get_digits(int num) {
    vector<int> out;
    while(num > 0) {
        out.push_back(num % 10);
        num = num / 10;
    }

    return out;
}

int main() {
    int n;
    cin >> n;

    vector<int> s(n + 1, 1e6);
    s[n] = 0;


    for(int i = n; i > 0; i--) {
        if(s[i] == 1e6) continue;
        vector<int> digs = get_digits(i);
        for(auto d: digs) {
            if(i - d >= 0) {
                s[i - d] = min(s[i - d], s[i] + 1);
            }
        }
    }


    cout << s[0] << endl;
}
