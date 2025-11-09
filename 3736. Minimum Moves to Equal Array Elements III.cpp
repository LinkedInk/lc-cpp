#include "pasta\headers.cpp"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int M = 0;
        for (int i : nums) {
            M = max(M, i);
        }
        int res = 0;
        for (int i : nums) {
            res += (M - i);
        }
        return res;
    }
};