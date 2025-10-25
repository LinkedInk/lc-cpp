#include "pasta\headers.cpp"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int earliestTruePos = nums.size() - 1;
        for (int i = nums.size() - 1; i > -1; i--) {
            if (i + nums[i] >= earliestTruePos) {
                earliestTruePos = i;
            }
        }
        return earliestTruePos == 0;
    }
};