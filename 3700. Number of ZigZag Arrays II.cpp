#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    // solution for smaller values of n, larger diff between l and r O((l-r)^2 n)
    // actual solution different O((l-r)^3 log(n))
    int zigZagArrays(int n, int l, int r) {
        const int totalPossibleElements = r - l + 1;
        const int modVal = 1000000007;

        if (n == 1) {
            return totalPossibleElements;
        }

        uint32_t down[totalPossibleElements]; // how many permutations come down to that number
        uint32_t up[totalPossibleElements]; // how many permutations go up to that number
        // init
        for (int i = 0; i < totalPossibleElements; ++i) {
            down[i] = 1;
            up[i] = 1;
        }

        uint32_t newDown[totalPossibleElements];
        uint32_t newUp[totalPossibleElements];

        uint32_t* currDownArr = down;
        uint32_t* nextDownArr = newDown;
        uint32_t* currUpArr = up;
        uint32_t* nextUpArr = newUp;

        // init
        nextDownArr[totalPossibleElements - 1] = 0;
        nextUpArr[0] = 0;
        while (n > 1) {
            for (int i = 1; i < totalPossibleElements; ++i) {
                nextUpArr[i] = (nextUpArr[i - 1] + currDownArr[i - 1]) % modVal;
            }
            for (int i = totalPossibleElements - 2; i >= 0; --i) {
                nextDownArr[i] = (nextDownArr[i + 1] + currUpArr[i + 1]) % modVal;
            }

            swap(currDownArr, nextDownArr);
            swap(currUpArr, nextUpArr);
            nextDownArr[totalPossibleElements - 1] = 0;
            nextUpArr[0] = 0;
            
            // for (int i = 0; i < totalPossibleElements; ++i) {
            //     cout << currDownArr[i];
            //     cout << currUpArr[i];
            //     cout << '\n';
            // }
            
            
            n--;
        }
        
        uint32_t total = 0;
        for (int i = 0; i < totalPossibleElements; ++i) {
            total += currDownArr[i];
            total += currUpArr[i];
            total %= modVal;
        }
        return total;
    }
};