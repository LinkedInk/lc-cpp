#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        stack<int> tempRes;
        int exponent = 10;
        while (n > 0) {
            int component = n % exponent;
            if (component != 0) tempRes.push(n % exponent);
            n -= component;
            exponent *= 10;
        }
        vector<int> res;
        while (!tempRes.empty()) {
            res.push_back(tempRes.top());
            tempRes.pop();
        }

        return res;

    }
};