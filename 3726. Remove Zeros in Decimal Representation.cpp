#include "pasta\headers.cpp"

class Solution {
public:
    long long removeZeros(long long n) {
        vector<long long> digits;
        while (n > 0) {
            if (n % 10 != 0) {
                digits.push_back(n % 10);
            }
            n /= 10;
        }
        long long res = 0;
        long long idx = 1;
        for (long long d : digits) {
            res += d * idx;
            idx *= 10;
        }
        return res;
    }
};