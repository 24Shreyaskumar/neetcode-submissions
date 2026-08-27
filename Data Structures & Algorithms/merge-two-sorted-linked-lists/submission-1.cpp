/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* h1 = list1;
        ListNode* h2 = list2;

        ListNode* h3;
        if (h1->val <= h2->val)
            h3 = h1, h1 = h1->next;
        else
            h3 = h2, h2 = h2->next;
        
        ListNode* it = h3;

        while (h1 && h2) {
            if (h1->val <= h2->val)
                it->next = h1, h1 = h1->next;
            else
                it->next = h2, h2 = h2->next;
            it = it->next;
        }

        while (h1) {
            it->next = h1;
            it = it->next;
            h1 = h1->next;
        }

        while (h2) {
            it->next = h2;
            it = it->next;
            h2 = h2->next;
        }

        return h3;
    }
};
