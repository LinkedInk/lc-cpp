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
    string longestPalindrome(string s) {
        int max = 0;
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            string temp = move(expandOddPalindrome(s, i));
            if (temp.size() > max) {
                max = temp.size();
                res = move(temp);
            }
            if (i + 1 < s.size() && s[i+1] == s[i]) {
                temp = move(expandEvenPalindrome(s, i, i + 1));
                if (temp.size() > max) {
                    max = temp.size();
                    res = move(temp);
                }
            }
        }

        return res;
    }

    string expandOddPalindrome(string& s, int pos) {
        int l = pos - 1;
        int r = pos + 1;
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        l++;
        string res;
        for (int i = l; i < r; i++) {
            res.push_back(s[i]);
        }
        return res;
    }

    string expandEvenPalindrome(string& s, int posL, int posR) {
        int l = posL - 1;
        int r = posR + 1;
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                l--;
                r++;
            } else {
                break;
            }
        }
        l++;
        string res;
        for (int i = l; i < r; i++) {
            res.push_back(s[i]);
        }
        return res;
    }

};