#include "pasta\headers.cpp"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return dfs(candidates, target, 0);
    }

    vector<vector<int>> dfs(vector<int>& candidates, int target, int pos) {
        // cout << target << "|" << pos << endl;
        if (target == 0) {
            return {{}};
        }
        if (pos > candidates.size() - 1) {
            return {};
        }
        int val = candidates[pos];
        vector<vector<int>> res;
        // Include current value
        if (target >= val) {
            auto withVal = dfs(candidates, target - val, pos);
            addValToEachCombi(withVal, val);
            // Efficient append
            res.insert(res.end(), make_move_iterator(withVal.begin()),
                    make_move_iterator(withVal.end()));
        }

        // Exclude current value
        auto withoutVal = dfs(candidates, target, pos + 1);
        // No addValToEachCombi here — you only add val when it’s included
        res.insert(res.end(), make_move_iterator(withoutVal.begin()),
                make_move_iterator(withoutVal.end()));

        return res;
    }

    void addValToEachCombi(vector<vector<int>>& combi, int val) {
        for (vector<int>& v : combi) {
            v.push_back(val);
        }
    } 
};