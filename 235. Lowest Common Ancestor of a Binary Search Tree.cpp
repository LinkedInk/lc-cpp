#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:

    int foundCount = 0;
    TreeNode* fork = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfsBST(root, p, q);
        return fork;
    }

    void dfsBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return;
        }
        if (p->val < root->val && q->val < root->val) {
            dfsBST(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            dfsBST(root->right, p, q);
        } else {
            fork = root;
        }
    }

    void dfsNoBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return;
        }
        int initFound = foundCount;

        if (root == p || root == q) {
            foundCount++;
        }

        if (foundCount == 2) {
            return; // shortcut
        }

        dfsNoBST(root->left, p, q);
        if (foundCount == 2) {
            if (fork == nullptr && initFound == 0) fork = root;
            return;
        }

        dfsNoBST(root->right, p, q);
        if (foundCount == 2) {
            if (fork == nullptr && initFound == 0) fork = root;
            return;
        }

    }
};