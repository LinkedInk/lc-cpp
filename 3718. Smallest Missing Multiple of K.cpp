#include "pasta\headers.cpp"


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int multiple = 1;
        while (true) {
            if (containsK(nums, k * multiple)) {
                multiple++;
                continue;
            } else {
                return multiple * k;
            }
        }

        return multiple * k;
    }

    bool containsK(vector<int>& nums, int k) {
        for (int i : nums) {
            if (i == k) {
                return true;
            }
        }
        return false;
    }


};