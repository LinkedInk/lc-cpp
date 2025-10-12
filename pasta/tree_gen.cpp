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

    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        if (!root) {
            return "N";
        }
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                res.append("N,");
                continue;
            }
            q.push(node->left);
            q.push(node->right);
            res.append(to_string(node->val)).append(",");
        }
        return res;
    }
    
    // input string must describe the tree in a BFS format, include N as null
    static TreeNode* deserialize(string& data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (getline(ss, val, ',')) {
            TreeNode* node = q.front();
            q.pop();
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};