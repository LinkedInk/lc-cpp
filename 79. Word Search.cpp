#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:

    int rowMax, colMax;
    bool exist(vector<vector<char>>& board, string word) {

        rowMax = board.size();
        colMax = board[0].size();

        for (int row = 0; row < rowMax; row++) {
            for (int col = 0; col < colMax; col++) {
                // for each char, do a dfs
                if (dfs(board, row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int currCharPos) {
        if (currCharPos == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= rowMax || col >= colMax ||
            board[row][col] != word[currCharPos]) {
            return false;
        }

        board[row][col] = '!';
        bool result = dfs(board, row - 1, col, word, currCharPos + 1)
                    || dfs(board, row, col + 1, word, currCharPos + 1)
                    || dfs(board, row + 1, col, word, currCharPos + 1)
                    || dfs(board, row, col - 1, word, currCharPos + 1);
        board[row][col] = word[currCharPos];
        return result;
    }
};