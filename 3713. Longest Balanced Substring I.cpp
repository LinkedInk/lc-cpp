#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include "pasta/my_print.cpp"
using namespace std;

#define loopI(i, s, e) for (int i = s; i < e; i++)

class Solution {
public:
    int longestBalanced(string s) {
        int res = 1;
        loopI(i, 0, s.size()) {
            vector<int> count(26);
            loopI(j, i, s.size()) {
                int idx = s[j] - 'a';
                count[idx]++;
                if (isBalanced(count)) {
                    res = max(res, j - i + 1);
                }
                // MyPrint::print(count);
                cout << endl;
            }
        }
        return res;

    }
    bool isBalanced(vector<int> count) {
        int prev = 0;
        for (int c : count) {
            if (c == 0) {
                continue;
            } else {
                if (prev == 0) {
                    prev = c;
                } else {
                    if (prev != c) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};