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
