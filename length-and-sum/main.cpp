#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    vector<int> nums;
    int s2 = s;
    int lastNonZero;

    while(s2 > 0) {
        if(s2 > 9) {
            s2 -= 9;
            nums.push_back(9);
        } else {
            lastNonZero = s2;
            nums.push_back(s2);
            s2 -= s2;
        }
    }

    if(m == 1 && s == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    if(nums.size() > m || s == 0) {
        cout << "-1 -1" << endl;
        return 0;
    }

    bool addedZeroes = false;
    int lastNonZeroIndex = 0;

    vector<int> smallNums;
    if(nums.size() < m) {

        addedZeroes = true;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == lastNonZero) {
                lastNonZeroIndex = i;
            }
        };

        int diff = m - nums.size();
        for(int i = 0; i < diff; i++) {
            nums.push_back(0);
        }
    }


    for(int i = 0; i < nums.size(); i++) {
        smallNums.push_back(nums[i]);
    }

    if(addedZeroes == true) {
        smallNums[lastNonZeroIndex] -= 1;
        smallNums[smallNums.size() - 1] = 1;

    }

    reverse(smallNums.begin(), smallNums.end());

    for(int i = 0; i < smallNums.size(); i++) {
        cout << smallNums[i];
    }

    cout << " ";

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }

    cout << endl;
    return 0;
}
