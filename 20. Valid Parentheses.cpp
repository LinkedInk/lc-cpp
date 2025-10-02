#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c : s) {
            if (stack.empty() || !closes(stack.top(), c)) {
                stack.push(c);
            } else {
                stack.pop();
            }
        }
        return stack.empty();
    }

    bool closes(char a, char b) {
        if (a == '(') {
            return b == ')';
        }
        if (a == '[') {
            return b == ']';
        }
        if (a == '{') {
            return b == '}';
        }
        return false;
    }
};