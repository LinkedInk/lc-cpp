#include "pasta\headers.cpp"

class Solution {
public:
    int res = 0;
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i);
            if (i + 1 < s.size()) {
                expand(s, i, i+1);
            }
        }
        return res;
    }

    void expand(string& s, int startPos) {
        res++;
        int l = startPos - 1;
        int r = startPos + 1;
        while (l > -1 && r < s.size()) {
            if (s[l] == s[r]) {
                res++;
                l--;
                r++;
            } else {
                break;
            }
        }
    }
    

    void expand(string& s, int l, int r) {
        while (l > -1 && r < s.size()) {
            if (s[l] == s[r]) {
                res++;
                l--;
                r++;
            } else {
                break;
            }
        }
    }
};
