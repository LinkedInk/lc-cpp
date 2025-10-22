#include "pasta\headers.cpp"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        bool res = equals(root, subRoot);
        if (res) {
            return res;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }

    bool equals(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr || subRoot == nullptr) {
            return false;
        } else if (root->val != subRoot->val) {
            return false;
        } else {
            return equals(root->left, subRoot->left) && equals(root->right, subRoot->right);
        }
    }
};