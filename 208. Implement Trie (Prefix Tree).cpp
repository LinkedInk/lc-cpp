#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Trie {
public:
    Trie* children[26];
    bool wordEndsHere = false;

    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->wordEndsHere = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->wordEndsHere;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie* children[26];
    bool wordEndsHere = false;

    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->wordEndsHere = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->wordEndsHere;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

// neetcode has different class names

// class PrefixTree {
// public:
//     PrefixTree* children[26];
//     bool wordEndsHere = false;

//     PrefixTree() {
//         for (int i = 0; i < 26; ++i) {
//             children[i] = nullptr;
//         }
//     }
    
//     void insert(string word) {
//         PrefixTree* curr = this;
//         for (char c : word) {
//             if (curr->children[c - 'a'] == nullptr) {
//                 curr->children[c - 'a'] = new PrefixTree();
//             }
//             curr = curr->children[c - 'a'];
//         }
//         curr->wordEndsHere = true;
//     }
    
//     bool search(string word) {
//         PrefixTree* curr = this;
//         for (char c : word) {
//             if (curr->children[c - 'a'] == nullptr) {
//                 return false;
//             }
//             curr = curr->children[c - 'a'];
//         }
//         return curr->wordEndsHere;
//     }
    
//     bool startsWith(string prefix) {
//         PrefixTree* curr = this;
//         for (char c : prefix) {
//             if (curr->children[c - 'a'] == nullptr) {
//                 return false;
//             }
//             curr = curr->children[c - 'a'];
//         }
//         return true;
//     }
// };
