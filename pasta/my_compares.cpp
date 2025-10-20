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

// for pq
struct PairMinMinHeap {
    template <typename T, typename U>
    bool operator()(pair<T, U>& p1, pair<T, U>& p2) const {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
};
struct PairMinMaxHeap {
    template <typename T, typename U>
    bool operator()(pair<T, U>& p1, pair<T, U>& p2) const {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};
struct PairMaxMaxHeap {
    template <typename T, typename U>
    bool operator()(pair<T, U>& p1, pair<T, U>& p2) const {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
};
struct PairMaxMinHeap {
    template <typename T, typename U>
    bool operator()(pair<T, U>& p1, pair<T, U>& p2) const {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

// for vectors
class MyCompares {
public:
    // think like a is left, and b is right
    // if bool is true, dont swap
    // if bool is false, swap
    static bool vecDesc(int a, int b) {
        return a > b;
    }
    static bool vecAsc(int a, int b) {
        return a < b;
    }
    template <typename T, typename U>
    static bool pairAscAsc(pair<T, U>& p1, pair<T, U>& p2) {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    template <typename T, typename U>
    static bool pairAscDesc(pair<T, U>& p1, pair<T, U>& p2) {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
    template <typename T, typename U>
    static bool pairDescAsc(pair<T, U>& p1, pair<T, U>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
    template <typename T, typename U>
    static bool pairDescDesc(pair<T, U>& p1, pair<T, U>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
};

