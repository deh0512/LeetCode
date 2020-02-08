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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* o = nullptr;
        ListNode* p = head;
        ListNode* q = head->next;
        head = head->next;
        while (p && q) {
            if (o) o->next = q;
            ListNode* temp = q->next;
            o = q->next = p;
            p->next = temp;
            p = p->next;
            if (p) q = p->next;
        }
        return head;
    }
};

