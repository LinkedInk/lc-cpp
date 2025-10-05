#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long xorSum = 0;
        bool nonZeroExists = false;
        for (int i : nums) {
            xorSum^=i;
            if (i != 0) {
                nonZeroExists = true;
            }
            // cout << xorSum << "|" << nonZeroExists << "\n";
        }

        if (xorSum != 0) {
            return nums.size();
        }

        if (nonZeroExists) {
            return nums.size() - 1;
        }

        return 0;

    }
};