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
    int longestBalanced(string& s) {
        // check for 1 char is longest balanced
        int ans = 1;
        int count = 1;
        loopI(i, 1, s.size()) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count); // in event the entire string is 1 char
        
        // check for 2 char is longest balanced
        ans = max(ans, longestBalanced2Char(s, 'a', 'b', 'c'));
        ans = max(ans, longestBalanced2Char(s, 'b', 'c', 'a'));
        ans = max(ans, longestBalanced2Char(s, 'c', 'a', 'b'));
        // check for 3 char
        ans = max(ans, longestBalanced3Char(s));
        return ans;
    }

    int longestBalanced2Char(string& s, char a, char b, char skip) {
        int res = 0;
        unordered_map<int, int> diffToPos;
        diffToPos[0] = -1;
        int ac = 0;
        int bc = 0;
        loopI(i, 0, s.size()) {
            if (s[i] == skip) {
                ac = 0;
                bc = 0;
                diffToPos.clear();
                diffToPos[0] = i;
                // cout << "BREAK\n";
                continue;
            }
            if (s[i] == a) {
                ac++;
            }
            if (s[i] == b) {
                bc++;
            }
            int diff = bc - ac;
            // cout << ac << "|" << bc << "|" << diff << "|" << diffToPos.count(diff) << endl;
            if (diffToPos.count(diff)) {
                res = max(res, i - diffToPos[diff]);
                // cout << res << endl;
            } else {
                diffToPos[diff] = i;
            }
        }
        // cout << res << endl << endl;
        return res;
    }

    int longestBalanced3Char(string& s) {
        int res = 0;
        unordered_map<string, int> diffToPos;
        diffToPos["0|0"] = -1;
        vector<int> counter(3);
        loopI(i, 0, s.size()) {
            const int idx = s[i] - 'a';
            counter[idx]++;
            string key = "";
            key.append(to_string(counter[1] - counter[0])).append("|").append(to_string(counter[2] - counter[0]));
            if (diffToPos.count(key)) {
                res = max(res, i - diffToPos[key]);
            } else {
                diffToPos[key] = i;
            }
        }
        return res;
    }
};