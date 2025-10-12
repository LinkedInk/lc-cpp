#include "pasta\headers.cpp"


// explanation:
// a perfect square number is where all its prime factors have an even power
// for each node val, do a prime factorisation and keep only the primes that have odd power
// if 2 numbers factorise such that they have the same primes that are odd power, 
// they form a perfect square number when multiplied together
class Solution {
public:
    unordered_map<int, int> oddPowerPrimesProductToCount;
    vector<vector<int>> edgeMap;
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        edgeMap = vector<vector<int>>(n);
        for (auto& e : edges) {
            edgeMap[e[0]].push_back(e[1]);
            edgeMap[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, nums);
    }

    long long dfs(int currNode, int parentNode, vector<int>& nums) {
        int res = 0; // total sum of this node and its child nodes where the perfect square condition applies
        int primeKey = getKey(nums[currNode]);

        if (oddPowerPrimesProductToCount.count(primeKey)) {
            res += oddPowerPrimesProductToCount[primeKey];
        }
        oddPowerPrimesProductToCount[primeKey]++;

        for (auto& neighbour : edgeMap[currNode]) {
            if (neighbour != parentNode) {
                res += dfs(neighbour, currNode, nums);
            }
        }
        
        oddPowerPrimesProductToCount[primeKey]--; // remove as we go back up the tree

        if (oddPowerPrimesProductToCount[primeKey] == 0) {
            oddPowerPrimesProductToCount.erase(primeKey); // memory optimisation
        }

        return res;
    }

    int getKey(int val) {
        int key = 1;

        // basic prime factorisation algo here
        // val must have a prime factorisation using primes >=i or ==1 at each step
        // if i squared is bigger than val, val cannot be factorised into i * (>=i)
        // smaller prime values have already been factorised out
        // the remaining value therefore is a prime or 1 ie fully factorised
        for (int i = 2; i*i <= val; i++) {
            int primecount = 0;
            while (val % i == 0) {
                primecount++;
                val /= i;
            }
            if (primecount % 2 != 0) {
                key *= i;
            }
        }

        if (val > 1) { // if there is a prime remaining
            key *= val;
        }
        return key;
    }
};