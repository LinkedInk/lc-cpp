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

class MyPrint {
public:
    // stringfy methods
    // primitives
    template <typename T>
    static string stringfy(T& i) {
        return to_string(i);
    }
    static string stringfy(string& i) {
        return i;
    }
    static string stringfy(char& i) {
        string res;
        res.push_back(i);
        return res;
    }
    // data structures
    template <typename T, typename U>
    static string stringfy(pair<T, U>& p) {
        string res = "(";
        res.append(stringfy(p.first));
        res.append(",");
        res.append(stringfy(p.second));
        res.append(")");
        return res;
    }
    template <typename T>
    static string stringfy(vector<T>& v) {
        string res = "[";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                res.append(",");
            }
            res.append(stringfy(v[i]));
        }
        res.append("]");
        return res;
    }
    template <typename T, typename U>
    static string stringfy(unordered_map<T, U>& map) {
        string res = "{";
        for (pair<const T, U>& e : map) {
            res.append(stringfy(e));
            res.append(",");
        }
        res.pop_back();
        res.append("}");
        return res;
    }
    template <typename T>
    static string stringfy(unordered_set<T>& set) {
        string res = "{";
        for (const T& e : set) {
            res.append(stringfy(e));
            res.append(",");
        }
        res.pop_back();
        res.append("}");
        return res;
    }
    template <typename T, typename U, typename V>
    static string stringfy(priority_queue<T, U, V>& pq) {
        vector<T> temp;
        while (!pq.empty()) {
            temp.emplace_back(pq.top());
            pq.pop();
        }
        string res = stringfy(temp);
        for (T& e : temp) {
            pq.emplace(e);
        }
        return res;
    }

    // print wrappers
    template <typename T>
    static void print(T& e) {
        cout << stringfy(e);
        cout << endl;
    }
    template <typename T>
    static void print(T& e, bool b) {
        cout << stringfy(e);
        if (!b) {
            cout << endl;
        }
    }
};