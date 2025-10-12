#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

#include "pasta/my_print.cpp"

// nums.size() <= 100
// nums[i] <= 100

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> freqs(101);
        for (int num : nums) {
            freqs[num] += 1;
        }

        int total = 0;
        for (int i = 0; i < 101; i++) {
            if (freqs[i] % k == 0) {
                total += i * freqs[i];
            }
        }
        return total;
    }
};