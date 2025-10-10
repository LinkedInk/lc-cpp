#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    TreeNode* children[26];
    int idx;
    int refs;

    TreeNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int i) {
        TreeNode* cur = this;
        cur->refs++;
        for (char c : word) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TreeNode();
            }
            cur = cur->children[index];
            cur->refs++;
        }
        cur->idx = i;
    }
};