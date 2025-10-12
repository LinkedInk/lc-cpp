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

class TreeGen {
public:
    static TreeNode* gen(vector<int>& v) {
        if (v.size() == 0) {
            return nullptr;
        }
        queue<TreeNode*> nextLayer;
        queue<TreeNode*> currentLayer;
        TreeNode* root = new TreeNode(v[0]);
        currentLayer.push(root);
        for (int i = 1; i < v.size(); i++) {
            if (currentLayer.size() == 0) {
                swap(currentLayer, nextLayer);
            }
            TreeNode* node = currentLayer.front();
            if (node->left == nullptr) {
                node->left = new TreeNode(v[i]);
                nextLayer.push(node->left);
            } else if (node->right != nullptr) {
                node->right = new TreeNode(v[i]);
                nextLayer.push(node->right);
                currentLayer.pop();
            }
        }
        return root;
    }
};