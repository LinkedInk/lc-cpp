#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry = b;
        int res = a;
        while (carry != 0) {
            int newCarry = (res & carry) << 1; // bitwise AND + left shit by 1
            res ^= carry; // perform the "addition" using XOR
            carry = newCarry;
        }
        return res;
    }
};