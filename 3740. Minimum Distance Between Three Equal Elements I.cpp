#include "pasta\headers.cpp"

class Solution {
public:
    int minimumDistance(vector<int> nums) {
        const int n = nums.size();
        int res = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == curr) {
                    count++;
                }
                if (count == 3) {
                    res = min(res, (j - i) * 2);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            return -1;
        }
        return res;
    }
};