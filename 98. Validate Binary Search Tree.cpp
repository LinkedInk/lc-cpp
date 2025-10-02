#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
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
    bool isValidBST(TreeNode* root) {
        return recurse(root, LONG_MIN, LONG_MAX);
    }

    bool recurse(TreeNode* root, long leftBound, long rightBound) {
        if (root == nullptr) {
            return true;
        }
    
        if (root->val <= leftBound || root->val >= rightBound) {
            return false;
        }

        return recurse(root->left, leftBound, root->val) && recurse(root->right, root->val, rightBound);
    }
};