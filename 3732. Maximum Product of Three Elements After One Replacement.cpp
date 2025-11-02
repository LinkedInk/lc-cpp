#include "pasta\headers.cpp"

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        long long val = 100000;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        
        long long product = (long long)nums[n] * (long long)nums[n - 1];
        
        if (product < 0) {
            product *= -1;
            product *= val;
        } else if (product > 0) {
            product *= val;
        } else {
            return 0;
        }
        return product;

    }
};