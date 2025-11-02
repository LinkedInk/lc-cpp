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
class Solution {
public:
    long long countStableSubarrays(vector<int> capacity) {
        vector<long long> sumToLeft;
        long long sum = 0;
        for (int i = 0; i < capacity.size(); i++) {
            sum += capacity[i];
            sumToLeft.push_back(sum);
        }
        unordered_map<pair<int, long long>, int> capAndSumToLeftToCount;
        long long res = 0;
        for (int r = 0; r < capacity.size(); r++) {
            int cap = capacity[r];
            long long lsum = sumToLeft[r];
            if (r >= 2) {
                int lcap = capacity[r - 2];
                long long llsum = sumToLeft[r - 2];
                capAndSumToLeftToCount[pair(lcap, llsum)] += 1;
            }
            if (capAndSumToLeftToCount.count(pair(cap, lsum - cap - cap))) {
                res += capAndSumToLeftToCount[pair(cap, lsum - cap - cap)];
            }
        }
        return res;
    }
};