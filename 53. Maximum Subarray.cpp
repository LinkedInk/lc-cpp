#include "pasta\headers.cpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // the maxSubArray must have a beginning and an end
        // so we calculate the max value a position can have that includes itself as the beginning of the subarray
        int res = nums.back();
        int rightMax = nums.back();
        for (int i = nums.size() - 2; i > -1; i--) {
            rightMax = max(rightMax + nums[i], nums[i]); // include this element + right, or just this element
            res = max(res, rightMax);
        }
        return res;
    }
};