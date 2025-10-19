#include "pasta\headers.cpp"

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        priority_queue <char> maxHeap;
        unordered_map<char, int> letterToCount;
        string res;
        // count the chars we have to form target
        for (char c : s) {
            letterToCount[c]++;
        }
        // print(letterToCount);

        // try to form target
        for (char tc : target) {
            if (letterToCount[tc] != 0) { // if theres still count left
                res.push_back(tc);
                letterToCount[tc]--;
            } else {
                break;
            }
        }

        // special case where s can form target exactly
        if (res.length() == target.length()) {
            maxHeap.push(res.back());
            res.pop_back();
        } else {
            fillMaxHeap(letterToCount, maxHeap);
        }

        int idx = res.length();
        char tc = target[idx];
        bool solved = false;
        while (!solved) {
            // cout << res << "|";
            string smallestCharBiggerEqualsTarget = getSmallestCharBiggerEqualsTarget(maxHeap, tc);
            if (smallestCharBiggerEqualsTarget != "") {
                solved = true;
                res.append(smallestCharBiggerEqualsTarget);
            } else {
                if (res.length() == 0) {
                    solved = true;
                    continue;
                }
            // cout << "tre" << "|";
                maxHeap.push(res.back());
                res.pop_back();
                idx--;
                tc = target[idx];
            }
            // cout << "END" << endl;
        }
        
        return res == "" ? "" : res.append(formSmallest(maxHeap));
    }

    string getSmallestCharBiggerEqualsTarget(priority_queue<char>& maxHeap, char target) {
        vector<char> temp;
        while (!maxHeap.empty()) {
            if (maxHeap.top() > target) {
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            } else {
                break;
            }
        }

        if (temp.size() == 0) { // every thing smaller
            addCharToHeap(temp, maxHeap);
            // cout << "here1" << "|";
            return "";
        }

        string s{temp.back()};
        temp.pop_back();
        addCharToHeap(temp, maxHeap);
        return s;
    }

    void addCharToHeap(vector<char>& v, priority_queue<char>& maxHeap) {
        for (char c : v) {
            maxHeap.push(c);
        }
    }

    string formSmallest(priority_queue<char>& maxHeap) {
        string res;
        priority_queue <char, vector<char>, greater<char> > minHeap;
        while (!maxHeap.empty()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }

    void fillMaxHeap(unordered_map<char, int>& letterToCount, priority_queue<char>& maxHeap) {
        for (pair<const char, int>& p : letterToCount) {
            for (int i = 0; i < p.second; i++) {
                maxHeap.push(p.first);
            }
        }
    }

    void print(unordered_map<char, int>& letterToCount) {
        for (pair<char, int> e : letterToCount) {
            cout << e.first << "," << e.second << "|";
        }
        cout << endl;
    }
};