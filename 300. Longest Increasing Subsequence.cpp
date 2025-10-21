#include "pasta\headers.cpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> lis;  // lis[i] = smallest possible tail of an increasing subsequence of length (i+1)

        for (int num : nums) {
            // Find where this number would go in the current LIS
            auto it = lower_bound(lis.begin(), lis.end(), num);

            if (it == lis.end()) {
                // If num is greater than all tails, append it
                lis.push_back(num);
            } else {
                // Otherwise, replace the first element >= num
                *it = num;
            }
            // MyPrint::print(lis);
        }

        return lis.size();
    }
};
