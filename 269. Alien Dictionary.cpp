#include "pasta\headers.cpp"


class Solution {
public:
    vector<vector<int>> directedEdge;
    vector<int> exists;

    vector<int> visited;
    vector<int> checked;

    string res = "";
    bool isValid = true;
    string foreignDictionary(vector<string>& words) {
        directedEdge.assign(26, vector(26, 0));
        exists.assign(26, -1);
        dfsEdgeAdd(words, 0, words.size(), 0);
        // MyPrint::print(exists);
        // MyPrint::print(directedEdge);
        if (!isValid) {
            return "";
        }
        // do loop
        visited.assign(26, 0);
        checked.assign(26, 0);
        if (isExistLoop()) {
            return "";
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool isExistLoop() {
        for (int i : exists) {
            if (i != -1) {
                visited.assign(26, 0);
                bool res = checkloop(i);
                if (res) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkloop(int start) {
        if (checked[start] == 1) {
            return false;
        }
        if (visited[start] == 1) {
            return true;
        }
        visited[start] = 1;
        for (int i = 0; i < 26; i++) {
            int next = directedEdge[start][i];
            if (next == 0) {
                continue;
            }
            bool res = checkloop(i);
            if (res) {
                return true;
            }
        }
        checked[start] = 1;
        res.push_back(start + 'a');
        return false;
    }

    void dfsEdgeAdd(vector<string>& words, int i, int j, int layerCount) {
        char prev = 0;
        int nextRangeI = i;
        // originally intended for this method to add all edges
        // but since it is not necessary that the input is of valid lex order, i added this
        bool charAtLayer = false; 
        for (i; i < j; i++) {
            string& w = words[i];
            if (w.size() <= layerCount) { // string ends
                if (charAtLayer) {
                    isValid = false;
                }
                continue;
            }
            charAtLayer = true;
            char c = w.at(layerCount);
            exists[c - 'a'] = c - 'a';
            if (prev != 0 && c != prev) { // new edge
                directedEdge[prev - 'a'][c - 'a'] = 1; // record edge
                dfsEdgeAdd(words, nextRangeI, i, layerCount + 1); // dfs next
                nextRangeI = i;
            }
            prev = c;
        }
        if (prev != 0) { // no new edge, but there could be a next layer
            dfsEdgeAdd(words, nextRangeI, i, layerCount + 1); // last segment
        }
    }
};
