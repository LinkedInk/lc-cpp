#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    string removeSubstring(string s, int k) {

        vector<pair<pair<int, int>, bool>> finalS;
        for (char c : s) {
            if (finalS.size() == 0) {
                finalS.emplace_back(pair(pair(0, 0), false));
            }

            pair<int, int>& toBeBalanced = finalS[finalS.size()-1].first;
            bool& closed = finalS[finalS.size()-1].second;

            if (c == '(') {
                if (closed) {
                    finalS.emplace_back(pair(1, 0), false);
                } else {
                    toBeBalanced.first += 1;
                }
            } else {
                closed = true;
                toBeBalanced.second += 1;
                if (toBeBalanced.first >= k && toBeBalanced.second == k) {
                    toBeBalanced.first -= k;
                    toBeBalanced.second -= k;
                    closed = false;
                    if (toBeBalanced.first == 0 && toBeBalanced.second == 0) {
                        finalS.pop_back();
                    }
                }
            }
            // cout << toBeBalanced.first << "|" << toBeBalanced.second << "|" << closed << "\n";
        }

        string res;
        res.reserve(s.size());
        
        for (pair<pair<int, int>, bool>& p : finalS) {
            for (int i = 0; i < p.first.first; i++) {
                res.append("(");
            } 
            for (int i = 0; i < p.first.second; i++) {
                res.append(")");
            } 
        }
        return res;
    }
};