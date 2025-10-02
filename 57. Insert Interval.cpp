#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int currIntervalIdx = 0;
        int s = intervals.size();
        while (currIntervalIdx < s && intervals[currIntervalIdx][1] < newInterval[0]) {
            // if interval fully in front of new interval
            res.push_back(intervals[currIntervalIdx]);
            currIntervalIdx++;
        }

        // consolidate overlapping intervals
        while (currIntervalIdx < s && !(newInterval[1] < intervals[currIntervalIdx][0])) {
            // check if new interval is not fully in front of next interval
            newInterval[0] = min(newInterval[0], intervals[currIntervalIdx][0]);
            newInterval[1] = max(newInterval[1], intervals[currIntervalIdx][1]);
            currIntervalIdx++;
        }

        // add in new interval
        res.push_back(newInterval);

        // fill any remaining
        while (currIntervalIdx < s) {
            res.push_back(intervals[currIntervalIdx]);
            currIntervalIdx++;
        }
        return res;
    }
};
