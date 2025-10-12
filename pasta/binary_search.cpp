#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class BinarySearch {
public:
    static int bSearch(vector<int>& v, int target) {
        int l = 0;
        int r = v.size();
        int m = (r-l)/2;
        while (r > l) {
            if (v[m] == target) {
                return m;
            }
            if (v[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
            m = (r+l)/2;
        }
        return -1;
    }
};