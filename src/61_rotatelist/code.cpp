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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k < 0) {
            return nullptr;
        }
        if (k == 0) {
            return head;
        }
        ListNode* counter = head;
        ListNode* previous = nullptr;
        for (auto i = 0; i < k; ++i) {
            previous = counter;
            if (counter->next == nullptr) {
                auto length = i + 1;
                // There's a possibility that we've already bypassed
                // the point where we should have exited, so add
                // the length of the list to make one more cycle
                k = (k % length) + length;
            }
            counter = counter->next == nullptr ? head : counter->next;
        }
        if (previous == counter || counter == head) {
            // There's only one node or k is the length of the list
            return head;
        }
        ListNode* newHead = head;
        ListNode* newHeadPrevious = nullptr;
        while (counter != nullptr) {
            previous = counter;
            counter = counter->next;
            newHeadPrevious = newHead;
            newHead = newHead->next == nullptr ? head : newHead->next;
        }
        previous->next = head;
        newHeadPrevious->next = nullptr;
        return newHead;
    }
};

