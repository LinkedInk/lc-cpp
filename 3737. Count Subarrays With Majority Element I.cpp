#include "pasta\headers.cpp"

class Solution {
public:
    int countMajoritySubarrays(vector<int> nums, int target) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int TAC = 0;
            int TC = 0;
            for (int j = i; j < n; j++) {
                TC++;
                if (nums[j] == target) {
                    TAC++;
                }
                if (TAC > 0 && (TC / TAC) < 2) {
                    res++;
                }
            }
        }
        return res;
    }
};