#include "pasta\headers.cpp"

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size()) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        unordered_map<int, int> visited;
        unordered_map<int, vector<int>> node;
        for (auto& p : edges) {
            visited[p[0]] = 0;
            visited[p[1]] = 0;
            node[p[0]].push_back(p[1]);
            node[p[1]].push_back(p[0]);
        }
        bool isValid = dfs(visited, node, edges[0][0], edges[0][0]);
        if (!isValid) return false;
        for (auto& p : visited) {
            if (p.second == 0) {
                return false;
            }
        }
        return true;
    }

    bool dfs(unordered_map<int, int>& visited, unordered_map<int, vector<int>>& node, int curr, int prev) {
        if (visited[curr] == 1) {
            return false;
        }
        visited[curr] = 1;
        for (auto& c : node[curr]) {
            if (c != prev) {
                bool next = dfs(visited, node, c, curr);
                if (!next) {
                    return false;
                }
            }
        }
        return true;
    }
};

