#include "pasta\headers.cpp"

class Solution {
public:
    int longestSubarray(vector<int> nums) {
        const int n = nums.size();
        vector<vector<int>> LR;
        int prev = INT_MIN;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < prev) {
                LR.push_back({l, i - 1});
                l = i;
            }
            prev = nums[i];
        }
        LR.push_back({l, n -1});
        // MyPrint::print(LR);

        if (LR.size() == 1) {
            return n;
        }
        int res = LR[0][1] - LR[0][0] + 1 + 1;
        for (int i = 1; i < LR.size(); i++) {
            res = max(res, LR[i][1] - LR[i][0] + 1 + 1);
            if (LR[i][1] == LR[i][0] || LR[i-1][1] == LR[i-1][0]) {
                continue; // if either sections are of size 1;
            }
            // both sections size min 2
            if (checkMergePossible(LR[i-1][1] - 1, LR[i][0] + 1, nums)) {
                res = max(res, LR[i][1] - LR[i-1][0] + 1);
            }
        }
        return res;
    }
    bool checkMergePossible(int l, int r, vector<int>& v) {
        if (v[r] < v[l]) {
            return false;
        }
        if (v[r-1] >= v[l]) {
            return true;
        }
        if (v[l+1] <= v[r]) {
            return true;
        }
        return false;
    }
};