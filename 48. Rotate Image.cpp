#include "pasta\headers.cpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;
        while (l < r) {
            for (int diff = 0; diff < r - l; diff++) {
                int& top = matrix[l][l + diff];
                int& right = matrix[l + diff][r];
                int& bottom = matrix[r][r - diff];
                int& left = matrix[r - diff][l];
                swap(top, left);
                swap(left, bottom);
                swap(bottom, right);
            }
            l++;r--;
        }
    }
};