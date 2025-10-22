#include "pasta\headers.cpp"

class Solution {
public:
    vector<int> cc;
    int characterReplacement(string s, int k) {
        cc.assign(26, 0);
        int l = 0;
        int r = 0;
        int res = 0;
        for (char c : s) {
            cc[c - 'A']++;
            r++;
            while (replacement() > k) {
                cc[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l);
        }
        return res;
    }

    int replacement() {
        int m = 0;
        int total = 0;
        for (int i : cc) {
            m = max(m, i);
            total += i;
        }
        return total - m;
    }
};