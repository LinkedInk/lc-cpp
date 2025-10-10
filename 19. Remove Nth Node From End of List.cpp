#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nthAway = head;
        for (int i = 0; i < n; i++) {
            if (nthAway->next != nullptr) {
                nthAway = nthAway->next;
            }
        }
        if (nthAway == nullptr) {
            return head->next;
        }
        ListNode* prev = head;
        while (nthAway->next != nullptr) {
            nthAway = nthAway->next;
            prev = prev->next;
        }

        
        prev->next = prev->next->next;
        return head;


    }
};