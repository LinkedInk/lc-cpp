#include "pasta\headers.cpp"

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
    bool isMatch(string& s, string& p, int SIDX, int PIDX) {
        while (SIDX < s.size() && PIDX < p.size()) {
            if (isMultiChar(p, PIDX)) {
                int CSIDX = SIDX;
                while (SIDX < s.size() && (s.at(SIDX) == p.at(PIDX) || p.at(PIDX) == '.')) {
                    SIDX++;
                }
                PIDX += 2;
                while (SIDX != CSIDX && !isMatch(s, p, SIDX, PIDX)) { // backtrack
                    SIDX--;
                }
            } else {
                if (s.at(SIDX) == p.at(PIDX) || p.at(PIDX) == '.') {
                    SIDX++;
                    PIDX++;
                } else {
                    return false;
                }
            }
        }
        while (PIDX < p.size() && isMultiChar(p, PIDX)) {
            PIDX+=2;
        }
        return SIDX >= s.size() && PIDX >= p.size();
    } 
    bool isMultiChar(string& p, int PIDX) {
        if (PIDX == p.size() - 1) {
            return false;
        } else {
            return '*' == p.at(PIDX + 1);
        }
    }
};