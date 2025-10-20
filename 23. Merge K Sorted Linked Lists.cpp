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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (auto& node : lists) {
            res = merge2Lists(res, node);
        }
        return res;

    }

    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a) {
            tail->next = a;
        }
        if (b) {
            tail->next = b;
        }
        return head->next;
    }
};