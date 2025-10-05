
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1; 
        long diff = 0;
        int prevL = 0;
        int prevR = 0;

        while (l < nums.size() && nums[l] > prevL && r > -1 && nums[r] > prevR) {
            diff += nums[l];
            diff -= nums[r];
            prevL = nums[l];
            prevR = nums[r];
            l++;
            r--;
        }

        while (l < nums.size() && nums[l] > prevL) {
            diff += nums[l];
            prevL = nums[l];
            l++;
        }

        while (r > -1 && nums[r] > prevR) {
            diff -= nums[r];
            prevR = nums[r];
            r--;
        }

        if (r >= l) {
            return -1;
        }
        if (l - r == 1) {
            return abs(diff);
        }

        return min(abs(diff + nums[l-1]), abs(diff - nums[l-1]));
    }
};