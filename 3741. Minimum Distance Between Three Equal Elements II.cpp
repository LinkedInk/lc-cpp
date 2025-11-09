#include "pasta\headers.cpp"

class Solution {
public:
    int minimumDistance(vector<int> nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> M;
        int res = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int key = nums[i];
            MyPrint::print("key", key);
            M[key].push_back(i);
            vector<int>& pos = M[key];
            // MyPrint::print("pos", pos);
            if (pos.size() > 2) {
                res = min(res, (pos.back() - pos[pos.size() - 3]) * 2);
                found = true;
            }
            // MyPrint::print("res", res);
        }
        return found ? res : -1;
    }
};