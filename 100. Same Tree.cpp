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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack <TreeNode*> pStack;
        stack <TreeNode*> qStack;

        pStack.push(p);
        qStack.push(q);

        while (!pStack.empty()) {
            TreeNode* pNode = pStack.top();
            TreeNode* qNode = qStack.top();
            
            pStack.pop();
            qStack.pop();

            if (pNode == nullptr && qNode == nullptr) {
                continue;
            }

            if (pNode == nullptr || qNode == nullptr || pNode->val != qNode->val) {
                return false;
            }

            pStack.push(pNode->left);
            qStack.push(qNode->left);
            pStack.push(pNode->right);
            qStack.push(qNode->right);

        }
        return true;
    }
};