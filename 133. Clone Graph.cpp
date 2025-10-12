#include "pasta/headers.cpp"


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> oldToNewMap;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        return dfs(node);

    }

    Node* dfs(Node* node) {
        if (oldToNewMap.count(node)) { // already cloned
            return oldToNewMap[node];
        }
        Node* cloned = new Node(node->val);
        oldToNewMap[node] = cloned;

        for (Node* n : node->neighbors) {
            Node* clonedNeighbour = dfs(n);
            cloned->neighbors.push_back(clonedNeighbour);
        }
        return cloned;
    }
};