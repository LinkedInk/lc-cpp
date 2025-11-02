#include "pasta\headers.cpp"

class Solution {
public:
    vector<int> cc;
    string mid = "";
    string t = "";
    string ht = "";
    string finalRes = "";
    string lexPalindromicPermutation(string s, string target) {
        cc.assign(128,0);
        ht = target.substr(0, target.size() / 2);
        t = target;
        for (char c : s) {
            cc[c]++;
        }
        int isOdd = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (cc[c] % 2) {
                mid.push_back(c);
                isOdd++;
                cc[c]--;
            }
        }
        if (isOdd > 1) {
            return "";
        }
        string res = "";
        bt(res, false);
        return finalRes;
    }
    bool bt(string& res, bool greater) {
        if (res.size() == ht.size()) {
            return isValid(res);
        }
        char start = ht[res.size()];
        if (greater) {
            start = 'a';
        }
        for (;start <= 'z'; start++) {
            if (cc[start] > 0) {
                cc[start]-=2;
                res.push_back(start);
                if (bt(res, greater)) {
                    return true;
                }
                res.pop_back();
                cc[start]+=2;
            }
            greater = true;
        }
        return false;
    }
    bool isValid(string& res) {
        string C = res;
        string R = C;
        reverse(R.begin(), R.end());
        C.append(mid).append(R);
        if (C > t) {
            finalRes.append(C);
            return true;
        } else {
            return false;
        }
    }
};