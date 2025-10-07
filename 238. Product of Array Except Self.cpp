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
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t len = nums.size();
        vector<int> res(len);
        uint32_t sum=1;
        for(int i=0;i<len;i++){
            res[i]=sum;
            sum*=nums[i];
        }
        // printVec(res);
        sum=1;
        for(int i=len-1;i>-1;i--){
            res[i]=sum*res[i];
            sum*=nums[i];
        }
        // printVec(res);
        return res;
    }

    // void printVec(vector<int>& nums) {
    //     for (auto i : nums) {
    //         cout << i << "|";
    //     }
    //     cout << '\n';
    // }
};