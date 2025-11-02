#include "pasta\headers.cpp"

class Solution {
public:
    vector<vector<pair<int, int>>> flowsInto;
    vector<vector<int>> *h = nullptr;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = &heights;
        flowsInto.assign(heights.size(), vector<pair<int, int>>(heights[0].size(), {-1,-1}));
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights.size() - 1, j, -10, 1);
            dfs(0, j, -10, 0);
        }
        for (int i = 0; i < heights.size(); i++) {
            dfs(i, 0, -10, 0);
            dfs(i, heights[0].size()-1, -10, 1);
        }
        vector<vector<int>> res;
        for (auto& r : flowsInto) {
            for (auto& c : r) {
                if (c.first > -1 && c.second > -1) {
                    res.push_back({c.first, c.second});
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, int prev, int pos) {
        vector<vector<int>>& heights = *h;
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size()) {
            return;
        }
        if (prev > heights[r][c]) {
            return;
        }
        if (pos) {
            if (flowsInto[r][c].second > -1) {
                return;
            } else {
                flowsInto[r][c].second = c;
            }
        } else {
            if (flowsInto[r][c].first > -1) {
                return;
            } else {
                flowsInto[r][c].first = r;
            }
        }
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for (auto& p : dir) {
            dfs(r + p.first, c + p.second, heights[r][c], pos);
        }
    }
};