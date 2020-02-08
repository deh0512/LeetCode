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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* output = lists[0];
        for (auto i = 1; i < lists.size(); ++i) {
            if (!output) {
                output = lists[i];
                continue;
            }
            if (!lists[i]) continue;
            ListNode* o = output;
            ListNode* p = o->next;
            ListNode* q = lists[i];
            if (lists[i]->val < output->val) {
                q = output;
                o = output = lists[i];
                p = o->next;
            }
            else {
                o = output;
                p = o->next;
                q = lists[i];
            }
            while (o && p && q) {
                if (q->val < p->val) {
                    o = o->next = q;
                    ListNode* temp = q->next;
                    q->next = p;
                    q = temp;
                }
                else {
                    o = p;
                    p = p->next;
                }
            }
            while (q) {
                o = o->next = q;
                q = q->next;
            }
        }
        return output;
    }
};

