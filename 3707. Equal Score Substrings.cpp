#include "pasta/headers.cpp"
#include "pasta\my_print.cpp"

class Solution {
public:
    bool scoreBalance(string s) {
        const int diff = 'a' - 1;
        vector<int> dp;
        dp.assign(s.size(), 0);
        int prev = 0;
        for (int i = 0; i < s.size(); i++) {
            int val = s[i] - diff;
            dp[i] = prev + val;
            prev = dp[i];
        }
        if (dp[s.size() - 1] % 2 == 1) {
            return false;
        }
        int pos = bSearch(dp, dp[s.size() - 1] / 2);
        return pos == -1 ? false : true;
    }
    int bSearch(vector<int>& v, int target) {
        int l = 0;
        int r = v.size();
        int m = (r-l)/2;
        while (r > l) {
            if (v[m] == target) {
                return m;
            }
            if (v[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
            m = (r+l)/2;
        }
        return -1;
    }
};