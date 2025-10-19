#include "..\pasta\headers.cpp"



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
    // count max overlaps
    // ie started but yet to finish
    // ie if all schedule 1 day whats the min meeting rooms
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> timeAndStartOrEnd;
        for (auto& i : intervals) {
            timeAndStartOrEnd.emplace_back(i.start, 1);
            timeAndStartOrEnd.emplace_back(i.end, -1);
        }
        sort(timeAndStartOrEnd.begin(), timeAndStartOrEnd.end(), [](auto& pair1, auto& pair2) {
            return pair1.first == pair2.first ? pair1.second < pair2.second : pair1.first < pair2.first;
        });

        int res = 0, concurrentMeetings = 0;
        for (auto& p : timeAndStartOrEnd) {
            concurrentMeetings += p.second;
            res = max(res, concurrentMeetings);
        }
        return res;
    }
};