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
    int kthSmallest(TreeNode* root, int k) {
        pair<bool, int> res = dfs(root, k);
        return res.second;
    }

    pair<bool, int> dfs(TreeNode* root, int k) {
        if (root == nullptr) {
            return pair(false, 0);
        }
    
        pair<bool, int> left = dfs(root->left, k);
        if (left.first) {
            return left;
        }
        
        if (k - left.second == 1) {
            return pair(true, root->val);
        }

        pair<bool, int> right = dfs(root->right, k - left.second - 1);
        if (right.first) {
            return right;
        }

        return pair(false, left.second + 1 + right.second);
    }
};