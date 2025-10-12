#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include "pasta\my_print.cpp"
using namespace std;

class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        dfs(s, 0);
        // MyPrint::print(dp);
        // cout << '\n';
        return dp[0] == -1 ? 0 : dp[0];
    }

    int dfs(string& s, int pos) {
        // MyPrint::print(dp);
        // cout << pos << '\n';

        if (pos >= s.size()) {
            return 1;
        }

        if (dp[pos] != -1) {
            return dp[pos];
        }

        int total = 0;

        int first = s[pos] - '0';
        if (first > 0 && first < 10) {
            total += dfs(s, pos + 1);
        }

        if (pos + 1 < s.size()) {
            int second = s[pos + 1] - '0';
            int combined = first * 10 + second;
            if (combined > 9 && combined < 27) {
                total += dfs(s, pos + 2);
            }
        }
        dp[pos] = total;
        return total;
    }
};