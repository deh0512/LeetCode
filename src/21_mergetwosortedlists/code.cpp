/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto merged = new ListNode(0);
        auto head = merged;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                merged->next = new ListNode(l1->val);
                merged = merged->next;
                l1 = l1->next;
            }
            else {
                merged->next = new ListNode(l2->val);
                merged = merged->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            merged->next = new ListNode(l1->val);
            merged = merged->next;
            l1 = l1->next;
        }
        while (l2) {
            merged->next = new ListNode(l2->val);
            merged = merged->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

