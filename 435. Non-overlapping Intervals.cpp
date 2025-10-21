#include "pasta\headers.cpp"


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int earliestEnd = -100000;
        for (auto& p : intervals) {
            int start = p[0];
            int end = p[1];
            if (start >= earliestEnd) {
                earliestEnd = end;
            } else {
                res++;
                earliestEnd = min(earliestEnd, end);
            }
        }
        return res;
    }
};