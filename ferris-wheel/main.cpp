#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> children;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        children.push_back(c);
    }

    sort(children.begin(), children.end());
    vector<bool> used = vector<bool>(n, false);
    int total = 0;

    int lhs = 0;
    int rhs = n - 1; 
    while(lhs < rhs) {
        int c1 = children[lhs];
        int c2 = children[rhs];
        if(c1 + c2 <= x) {
            used[lhs] = true;
            used[rhs] = true;
            lhs++;
            rhs--;
            total++;
        } else {
            rhs--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) total++;
    }

    cout << total << endl;
    return 0;
}
