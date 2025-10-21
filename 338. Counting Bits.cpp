#include "pasta\headers.cpp"

class Solution {
public:
    // gcc built in function
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
    
    // using bitset
    
    vector<int> countBitz(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            bitset<32> b(i);
            res.push_back(b.count());
        }
        return res;
    }
};