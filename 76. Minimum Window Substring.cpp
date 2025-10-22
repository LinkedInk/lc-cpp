#include "pasta\headers.cpp"

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        vector<int> cnt;
        unordered_set<char> exists;
        cnt.assign(128, 0);
        for (char c : t) {
            cnt[c]++;
            exists.emplace(c);
        }

        int l = -1;
        int total = 0;
        int rightLimit = 0;
        // finds the first range that contains all in t
        for (int r = 0; r < s.size(); r++) {
            char currC = s[r];
            if (l == -1 && exists.count(currC) == 1) {
                l = r;
            }
            if (exists.count(currC) == 1) {
                if (cnt[currC] > 0) {
                    total++;
                }
                cnt[currC]--;
            }
            if (total == t.size()) {
                rightLimit = r + 1;
                break;
            }
        }
        if (total != t.size()) {
            return "";
        }
        // contineously shuffle to find the next ranges
        int minL = l;
        int minR = rightLimit;
        while (rightLimit < s.size()) {
            while (!exists.count(s[l]) || cnt[s[l]] < 0) { // shrinking
                cnt[s[l]]++;
                l++;
            }
            if (minR-minL > rightLimit - l) {
                minR = rightLimit;
                minL = l;
            }
            // go next range
            char target = s[l];
            cnt[s[l]]++;
            l++;
            total--;
            while (rightLimit < s.size()) { // growing
                char currC = s[rightLimit];
                if (exists.count(currC) == 1) {
                    cnt[currC]--;
                }
                if (currC == target) {
                    rightLimit++;
                    total++;
                    break;
                }
                rightLimit++;
            }
        }
        if (total == t.size()) {
            while (!exists.count(s[l]) || cnt[s[l]] < 0) { // one more shrinking
                cnt[s[l]]++;
                l++;
            }
            if (minR-minL > rightLimit - l) {
                minR = rightLimit;
                minL = l;
            }
        }
        return s.substr(minL, minR-minL);
    }
};