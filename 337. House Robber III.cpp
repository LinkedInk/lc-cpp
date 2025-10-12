#include "pasta\headers.cpp"


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
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

    // return pair, first is if the root passed in is robbed, second if its not
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return pair(0, 0);
        }

        pair<int, int> left = move(dfs(root->left));
        pair<int, int> right = move(dfs(root->right));

        pair<int, int> res;

        res.first = root->val + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        

        return res;
    }

};