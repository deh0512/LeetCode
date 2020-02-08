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
        auto cmp = [](ListNode* l, ListNode* r) {
            return r && (!l || r->val < l->val);
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q{cmp};
        ListNode* n;
        for (auto& list : lists) {
            n = list;
            while (n) {
                q.push(n);
                n = n->next;
            }
        }
        if (q.empty()) return nullptr;
        ListNode* output = q.top();
        q.pop();
        n = output;
        while (!q.empty()) {
            n = n->next = q.top();
            q.pop();
        }
        n->next = nullptr;
        return output;
    }
};

