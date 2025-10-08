#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> groupIdx(n);
        unordered_map<int, vector<int>> idxToMember;

        for (int i = 0; i < n; i++) {
            groupIdx[i] = i;
            idxToMember[i] = {i};
        }
        
        for (vector<int>& edge : edges) {
            if (groupIdx[edge[0]] == groupIdx[edge[1]]) {
                continue;
            }

            vector<int>& member0 = idxToMember[groupIdx[edge[0]]];
            vector<int>& member1 = idxToMember[groupIdx[edge[1]]];

            int erase = groupIdx[edge[1]];

            for (int member : member1) {
                groupIdx[member] = groupIdx[edge[0]];
            }

            move(member1.begin(), member1.end(), back_inserter(member0));

            idxToMember.erase(erase);
            // cout << erase << "erased ";
        }
        return idxToMember.size();
    }
};
