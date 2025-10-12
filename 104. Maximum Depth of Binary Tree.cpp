#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
    
    void dfs(TreeNode* root, int currDepth) {
        if (root != nullptr) {
            res = max(res, currDepth);
            dfs(root->left, currDepth + 1);
            dfs(root->right, currDepth + 1);
        }
    }
};