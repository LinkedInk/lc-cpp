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
    int preIdx = 0;
    int inIdx = 0;

    // goes to the left as much as it can when building, stop conditions as shown
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int eleAlrPlacedOnMyRight) {
        // bounds check, implies the build has been done
        if (preIdx >= preorder.size()) return nullptr;
        // when the next left most item is on this not yet generated node's right, and is already generated
        if (inorder[inIdx] == eleAlrPlacedOnMyRight) {
            inIdx++; // account for the alr generated part
            return nullptr; // nothing to generate
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]); // returns preIdx first before incrementing (post increment)
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, eleAlrPlacedOnMyRight);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};