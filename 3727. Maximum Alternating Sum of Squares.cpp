#include "pasta\headers.cpp"

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> tmp;
        for (int i : nums) {
            tmp.push_back(i * i);
        }
        sort(tmp.begin(), tmp.end());
        long long res = 0;
        int l = 0;
        int r = tmp.size() - 1;
        while (l < r) {
            res += tmp[r];
            res -= tmp[l];
            r--;
            l++;
        }
        if (l == r) {
            res += tmp[r];
        }
        return res;
    }
};