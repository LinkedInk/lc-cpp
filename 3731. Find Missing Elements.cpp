#include "pasta\headers.cpp"

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int curr = nums[0];
        for (int i : nums) {
            while (curr != i) {
                res.push_back(curr);
                curr++;
            }
            curr++;
        }
        return res;
    }
};