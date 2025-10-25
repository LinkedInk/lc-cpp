#include "pasta\headers.cpp"
template <class T>
inline void hash_combine(std::size_t& seed, const T& v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template <typename T, typename U>
struct hash<pair<T, U>> {
    size_t operator()(const pair<T, U>& p) const {
        std::hash<T> hasher;
        size_t hash = hasher(p.first);
        hash_combine(hash, p.second);
        return hash;
    }
};

template <typename T>
class DSU {
    unordered_map<int, vector<T>> indexToNode;
    unordered_map<T, int> nodeToIndex;
    int index = 0;
public:
    DSU() {
    }

    int addIfNotExist(T node) {
        if (nodeToIndex.count(node) == 0) {
            nodeToIndex[node] = index;
            indexToNode[index] = {node};
            index++;
        }
        return nodeToIndex[node];
    }

    bool UU(T node1, T node2) {
        int index1 = addIfNotExist(node1);
        int index2 = addIfNotExist(node2);
        if (index1 == index2) return false;
        vector<T>& nodes1 = indexToNode[index1]; 
        vector<T>& nodes2 = indexToNode[index2]; 
        if (nodes2.size() > nodes1.size()) {
            for (T& n : nodes1) {
                nodeToIndex[n] = index2;
            }
            move(nodes1.begin(), nodes1.end(), back_inserter(nodes2));
            indexToNode.erase(index1);
        } else {
            for (T& n : nodes2) {
                nodeToIndex[n] = index1;
            }
            move(nodes2.begin(), nodes2.end(), back_inserter(nodes1));
            indexToNode.erase(index2);
        }
        return true;
    }

    int countIndexes() {
        return indexToNode.size();
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        DSU<pair<int, int>> ds;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ds.addIfNotExist(pair(i, j));
                    for (auto& d : directions) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni >= 0 && nj >= 0 && ni < grid.size() &&
                            nj < grid[0].size() && grid[ni][nj] == '1') {
                            ds.UU({i, j}, {ni, nj});
                        }
                    }
                }
            }
        }
        return ds.countIndexes();
    }
};