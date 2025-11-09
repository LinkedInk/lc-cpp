#include "pasta\headers.cpp"

class Solution {
public:
    vector<vector<vector<int>>> TC;
    int m;
    int n;
    vector<vector<int>>* g;
    int t;
    int maxPathScore(vector<vector<int>> grid, int k) {
        m = grid.size();
        n = grid[0].size();
        TC.assign(m, vector(n, vector(k + 1, -2)));
        g = &grid;
        t = k;
        return dfsMemo(0, 0, k);
    }
    int dfsMemo(int i, int j, int k) {
        vector<vector<int>>& G = *g;
        if (i >= m || j >= n || k < 0) {
            return -1;
        }
        if (TC[i][j][k] != -2) {
            // cout << "fst "<< i << "|" << j << "|" << k <<",";
            // MyPrint::print("TC[i][j][k]", TC[i][j][k]);
            return TC[i][j][k];
        }
        if (i == m-1 && j == n-1) {
            if (G[i][j] != 0 && k == 0) {
                TC[i][j][k] = -1;
            } else {
                TC[i][j][k] = G[i][j];
            }   
            // cout << "2nd "<< i << "|" << j << "|" << k <<",";
            // MyPrint::print("TC[i][j][k]", TC[i][j][k]);
            return TC[i][j][k];
        }
        if (G[i][j] > 0) {
            k--;
        }
        int res1 = dfsMemo(i + 1, j, k);
        int res2 = dfsMemo(i, j + 1, k);
        int res = max(res1, res2);
        if (res != -1) {
            res = res + G[i][j];
        }
        if (G[i][j] > 0) {
            k++;
        }
        TC[i][j][k] = res;
        // cout << "last " << i << "|" << j << "|" << k <<"," << res1 << "|" << res2;
        // // MyPrint::print("TC2", TC);
        // MyPrint::print("TC[i][j][k]", TC[i][j][k]);
        return TC[i][j][k];
    }
};