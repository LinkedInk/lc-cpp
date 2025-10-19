#include "..\pasta\headers.cpp"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> preRecCount;
        preRecCount.assign(numCourses, 0);

        vector<vector<int>> preRecOf;
        preRecOf.assign(numCourses, {});

        for (auto& preR : prerequisites) {
            preRecCount[preR[0]] += 1;
            preRecOf[preR[1]].push_back(preR[0]);
        }

        queue<int> canTake;
        for (int course = 0; course < numCourses; course++) {
            if (preRecCount[course] == 0) {
                canTake.push(course);
            }
        }

        int finished = 0;
        while (!canTake.empty()) {
            int course = canTake.front();
            canTake.pop();
            finished++;
            for (int nextCourse : preRecOf[course]) {
                preRecCount[nextCourse]--;
                if (preRecCount[nextCourse] == 0) {
                    canTake.push(nextCourse);
                }
            }
        }
        return finished == numCourses;
    }
};