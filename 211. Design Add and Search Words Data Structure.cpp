#include "pasta\headers.cpp"
struct CNode {
    CNode* children[26];
    bool wordEnds;
};
class WordDictionary {
public:
    CNode* root;
    WordDictionary() {
        root = init();
    }
    
    void addWord(string word) {
        CNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = init();
            }
            curr = curr->children[c - 'a'];
        }
        curr->wordEnds = true;
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }

    bool dfsSearch(string& word, int pos, CNode* curr) {
        if (pos > word.size() || curr == nullptr) {
            return false;
        }
        if (pos == word.size()) {
            return curr->wordEnds;
        }
        if (word[pos] == '.') {
            for (CNode* c : curr->children) {
                if (c != nullptr) {
                    bool res = dfsSearch(word, pos + 1, c);
                    if (res) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            return dfsSearch(word, pos + 1, curr->children[word[pos] - 'a']);
        }
        
    }

    CNode* init() {
        CNode* n = new CNode();
        for (auto& c : n->children) {
            c = nullptr;
        }
        n->wordEnds = false;
        return n;
    }
};