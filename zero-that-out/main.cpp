#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if(c == 0) nums.pop_back();
        else nums.push_back(c);
    }

    int total = 0;
    for(int i = 0; i < nums.size(); i++) total += nums[i];

    cout << total << endl;

    return 0;
}

