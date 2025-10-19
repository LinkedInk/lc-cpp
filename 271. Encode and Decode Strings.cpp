#include "pasta\headers.cpp"

class Solution {
public:
    // the encoding should always contain the length of the string at the very beginning
    // ending on a fixed stop char that is not a number
    string encode(vector<string>& strs) {
        const string delimiter = "|";
        string res = "";
        for (string& s : strs) {
            res.append(to_string(s.size()));
            res.append(delimiter);
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size();) {
            string len;
            while (s[i] != '|') {
                len.push_back(s[i]);
                i++;
            }
            i++;
            int lenInt = stoi(len);
            string inner;
            while (lenInt) {
                inner.push_back(s[i]);
                i++;
                lenInt--;
            }
            res.emplace_back(move(inner));
        }
        return res;
    }
};
