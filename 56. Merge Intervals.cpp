#include "pasta\headers.cpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start = -1;
        int end = -1;
        for (auto& i : intervals) {
            if (i[0] <= end) {
                end = max(end, i[1]);
            } else {
                if (start != -1) {
                    res.push_back({start, end});
                }
                start = i[0];
                end = i[1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};