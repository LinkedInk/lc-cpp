#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr = nums[0];
        for (auto num : nums) {
            if (num != curr) {
                return 1;
            }
        }
        return 0;
    }
};