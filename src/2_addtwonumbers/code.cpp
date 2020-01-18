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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto overflow = false;
        ListNode* output = nullptr;
        ListNode* cur = nullptr;
        while (l1 || l2) {
            if (!cur) {
                cur = new ListNode{overflow ? 1 : 0};
                output = cur;
            }
            else {
                cur->next = new ListNode{overflow ? 1 : 0};
                cur = cur->next;
            }
            overflow = false;
            if (l1) {
                cur->val += (l1 ? l1->val : 0);
                l1 = l1->next;
            }
            if (l2) {
                cur->val += (l2 ? l2->val : 0);
                l2 = l2->next;
            }
            overflow = (cur->val / 10) > 0;
            cur->val %= 10;
        }
        if (overflow) {
            cur->next = new ListNode{1};
        }
        return output;
    }
};

