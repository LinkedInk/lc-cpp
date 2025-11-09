#include "pasta\headers.cpp"
class Solution {
public:
    long long minimumTime(vector<int> d, vector<int> r) {
        long long totalD = d[0] + d[1];
        long long LCM = lcm(r[0] , r[1]);
        long long LCMBlocks = totalD / (LCM - 1);
        long long LCMBlocksR = totalD % (LCM - 1);
        long long minBoundTime = LCMBlocks * LCM + LCMBlocksR;
        if (LCMBlocksR == 0) {
            minBoundTime--;
        }
        long long numBothDronesNoFly = LCMBlocks - (LCMBlocksR == 0 ? 1 : 0);
        long long gapsFor0 = minBoundTime/r[1] - numBothDronesNoFly;
        long long gapsFor1 = minBoundTime/r[0] - numBothDronesNoFly;

        if (gapsFor0 <= d[0] && gapsFor1 <= d[1]) {
            return minBoundTime;
        } else {
            if (gapsFor0 > d[0]) {
                return timeTaken(d[1], r[1]);
            } else {
                return timeTaken(d[0], r[0]);
            }
        }
    }
    long long timeTaken(int d, int r) {
        long long dPerSession = r - 1;
        long long fullSessions = d / dPerSession;
        long long remainder = d % dPerSession;

        long long totalTime = fullSessions * r;
        if (remainder == 0) {
            totalTime--;
        }
        totalTime += remainder;
        return totalTime;
    }
    // B search solution
    // long long LCM;
    // long long minimumTime(vector<int> d, vector<int> r) {
    //     LCM = lcm(r[0], r[1]);
    //     long long LB = 0;
    //     long long UB = LLONG_MAX;
    //     long long mid = (UB - LB) / 2 + LB;
    //     while (LB < UB) {
    //         if (possibleInTime(mid, d, r)) {
    //             UB = mid;
    //         } else {
    //             LB = mid + 1;
    //         }
    //         mid = (UB - LB)/2 + LB;
    //     }
    //     return UB;
    // }
    // bool possibleInTime(long long time, vector<int>& d, vector<int>& r) {
    //     long long maxD0 = time - time / r[0];
    //     long long maxD1 = time - time / r[1];
    //     long long maxD = time - time / LCM; 
    //     return maxD0 >= d[0] && maxD1 >= d[1] && maxD >= d[0] + d[1];
    // }
};