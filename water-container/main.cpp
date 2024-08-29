#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lhs = 0;
        int rhs = height.size() - 1;
        
        int max_area = 0;

        while(lhs != rhs) {
            max_area = max(max_area, min(height[lhs], height[rhs]) * (rhs-lhs));

            if(height[lhs] <= height[rhs]) {
                lhs++;
            } else {
                rhs--;
            }
        }

        return max_area;
    }
};
