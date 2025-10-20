#include "pasta\headers.cpp"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToCount;
        for (int i : nums) {
            if (numToCount.count(i)) {
                numToCount[i]++;
            } else {
                numToCount[i] = 1;
            }
        }
        vector<pair<int, int>> numToCountV;
        for (pair<const int, int>& e : numToCount) {
            numToCountV.emplace_back(e);
        }
        sort(numToCountV.begin(), numToCountV.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        
        vector<int> res;
        for (auto& e : numToCountV) {
            res.push_back(e.first);
            if (res.size() == k) {
                return res;
            }
        }
        return res;
    }
};