#include "pasta\headers.cpp"
// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& f, Interval& s) {
            return f.start == s.start ? f.end > s.end : f.start < s.start;
        });
        Interval prev(-1, -1);
        for (auto& i : intervals) {
            if (i.start < prev.end) {
                return false;
            }
            prev = i;
        }
        return true;
    }
};