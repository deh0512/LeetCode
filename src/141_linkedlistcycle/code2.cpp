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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        auto first = true;
        while (slow && fast) {
            if (slow == fast && !first) return true;
            else first = false;
            slow = slow->next;
            if (fast->next) fast = fast->next->next;
            else fast = nullptr;
        }
        return false;
    }
};

