#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    n++;
    while(true) {
        string s = to_string(n);
        set<char> digits;
        bool is_distinct = true;
        for(auto c: s) {
            if(digits.find(c) != digits.end()) {
                is_distinct = false;
            }

            digits.insert(c);
        }

        if(is_distinct) {
            cout << n << endl;
            return 0;
        }
        n++;
    }

    return 0;
}
