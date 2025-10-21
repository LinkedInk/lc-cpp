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
    int maxPathSum(TreeNode* root) {
        return dfs(root).first;
    }
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {-10000, -10000};
        }
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        pair<int, int> res;
        // res second is the max value that has one end at this root
        res.second = max(l.second + root->val, r.second + root->val);
        res.second = max(res.second, root->val);
        // res first is the absolute max value that this sub tree can contain
        res.first = max(l.first, r.first); // max of left max, right max
        res.first = max(res.first, l.second + r.second + root->val); // is a joined one bigger
        res.first = max(res.first, res.second); // or is a straight one from this root best
        return res;
    }
};
