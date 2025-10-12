#include "pasta\headers.cpp"

class Solution {
public:

    vector<int> dp;
    int rob(vector<int>& nums) {
        int res = 0;
        if (nums.size() < 3) {
            for (int n : nums) {
                res = max(res, n);
            }
            return res;
        }

        dp.assign(nums.size(), 0);

        loopi(i, 0, nums.size()) {
            int robValue = nums[i] + (i < 2 ? 0 : dp[i-2]);
            int noRobValue = (i < 1 ? 0 : dp[i-1]);
            dp[i] = max(robValue, noRobValue);
        }
        res = max(res, dp[nums.size()-1]);
        return res;
    }
};