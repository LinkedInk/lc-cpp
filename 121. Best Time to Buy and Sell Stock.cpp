#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int profit = 0;

        for (int price : prices) {
            if (price < minSoFar) {
                minSoFar = price;
            } else {
                profit = max(profit, price - minSoFar);
            }
        }
        return profit;

    }
};