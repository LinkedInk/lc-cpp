#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;

class MyTreeNode {
public:
    MyTreeNode* children[26];
    int idxOfWordEndingHere;

    MyTreeNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        idxOfWordEndingHere = -1;
    }

    void addWord(const string& word, int i) {
        MyTreeNode* cur = this;
        for (char c : word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new MyTreeNode();
            }
            cur = cur->children[index];
        }
        cur->idxOfWordEndingHere = i;
    }
};

class Solution {
public:
    vector<string> res;


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        MyTreeNode* tree = new MyTreeNode();
        for (int i = 0; i < words.size(); i++) {
            tree->addWord(words[i], i);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, tree, board, words);
            }
        }
        return res;
    }

    void dfs(int i, int j, MyTreeNode* currNode, vector<vector<char>>& board, vector<string>& words) {

        // cout << i << ',' << j << '|';
        if (i < 0 || j < 0 || !(i < board.size()) || !(j < board[0].size()) || // exceed bounds check
            board[i][j] == '!' || !currNode->children[board[i][j] - 'a']) {// been to check, no word uses this char check 
            // cout << "END" << '\n';
            return;
        }

        MyTreeNode* nextNode = currNode->children[board[i][j] - 'a'];
        if (nextNode->idxOfWordEndingHere != -1) {
            // cout << words[nextNode->idxOfWordEndingHere] << '\n';
            res.push_back(words[nextNode->idxOfWordEndingHere]);
            nextNode->idxOfWordEndingHere = -1;
        }

        char temp = board[i][j];
        board[i][j] = '!';

        dfs(i + 1, j, nextNode, board, words);
        dfs(i - 1, j, nextNode, board, words);
        dfs(i, j + 1, nextNode, board, words);
        dfs(i, j - 1, nextNode, board, words);

        board[i][j] = temp;

        // cout << '\n';
    }
};