#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;

class MyPrint {
public:
    static void print(vector<int>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                cout << ",";
            }
            cout << v[i];
        }
        cout << "]";
    }
    static void print(vector<vector<int>>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                cout << ",";
            }
            print(v[i]);
        }
        cout << "]";
    }
    static void print(vector<string>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                cout << ",";
            }
            cout << v[i];
        }
        cout << "]";
    }
    static void print(vector<vector<string>>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                cout << ",";
            }
            print(v[i]);
        }
        cout << "]";
    }
};