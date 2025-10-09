#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int mask = 1;
        int res = 0;
        for (int i = 0; i < 31; i++) {
            res += (n & mask) > 0;
            mask <<= 1;
        }
        return res;
    }
};