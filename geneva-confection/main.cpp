#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    stack<int> mt;
    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;
        mt.push(s);
    }
    
    stack<int> l;

    int current = 1;
    while (current <= n) {
        if(mt.size() > 0 && mt.top() == current) {
            mt.pop();
            current++;
            continue;
        } else if (l.size() != 0 && l.top() == current) {
            l.pop();
            current++;
            continue;
        } else if(mt.size() == 0 && l.size() != 0) {
            cout << "N" << endl;
            return;    
        } else {
            l.push(mt.top());
            mt.pop();
        }
    }

    cout << "Y" << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }

    return 0;    
}
