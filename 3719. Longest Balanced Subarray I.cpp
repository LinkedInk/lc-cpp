#include "pasta\headers.cpp"

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // 2 loops check if each set is balanced and get the max val
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> us;
            int evenc = 0;
            int oddc = 0;
            for (int j = i; j < nums.size(); j++) {
                int len = j - i + 1;
                int n = nums[j];
                if (us.count(n)) {
                    us[n]++;
                } else {
                    us[n] = 1;
                    if (n % 2 == 0) {
                        evenc++;
                    } else {
                        oddc++;
                    }
                }
                if (evenc == oddc) {
                    res = max(res, len);
                }
            }
        }
        return res;
    }
};