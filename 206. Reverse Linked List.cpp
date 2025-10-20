#include "pasta\headers.cpp"


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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* toBeReversed = head->next;
        head->next = nullptr;
        while (toBeReversed != nullptr) {
            ListNode* flipping = toBeReversed;
            toBeReversed = flipping->next;
            flipping->next = head;
            head = flipping;
        }
        return head;
    }
};