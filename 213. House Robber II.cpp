#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxAtWithLast;
    vector<int> maxAtNoLast;

    int rob(vector<int>& nums) {
        maxAtWithLast.assign(nums.size(), -1);
        maxAtNoLast.assign(nums.size(), -1);
        maxAtNoLast[nums.size()-1] = 0;

        maxAtNoLast[0] = nums[0] + dfs1(nums, 2);
        maxAtWithLast[0] = dfs2(nums, 1);

        return max(maxAtNoLast[0], maxAtWithLast[0]);

    }

    int dfs1(vector<int>& nums, int currPos) {
        if (currPos > nums.size() -1) {
            return 0;
        }

        if (maxAtNoLast[currPos] != -1) {
            return maxAtNoLast[currPos];
        }

        maxAtNoLast[currPos] = max(nums[currPos] + dfs1(nums, currPos + 2), dfs1(nums, currPos + 1));
        return maxAtNoLast[currPos];
    }

    int dfs2(vector<int>& nums, int currPos) {
        if (currPos > nums.size() -1) {
            return 0;
        }

        if (maxAtWithLast[currPos] != -1) {
            return maxAtWithLast[currPos];
        }
        
        maxAtWithLast[currPos] = max(nums[currPos] + dfs2(nums, currPos + 2), dfs2(nums, currPos + 1));
        return maxAtWithLast[currPos];
    }


};