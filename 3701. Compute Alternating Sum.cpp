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
    int alternatingSum(vector<int>& nums) {

        int res = 0;
        int add = true;
        for (int i : nums) {
            if (add) {
                res+=i;
            } else {
                res-=i;
            }
            add^=1;
        }
        return res;
        
    }
};