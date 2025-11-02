#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// copy below in order to the top if used

template <typename T, typename U>
struct hash<pair<T, U>> {
    size_t operator()(const pair<T, U>& p) const {
        size_t seed = hash<T>{}(p.first);
        return hash<U>{}(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
};
template <typename T>
struct hash<vector<T>> {
    size_t operator()(const vector<T>& v) const {
        std::size_t seed = 0;
        for (const T& x : v) {
            seed ^= std::hash<T>{}(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
