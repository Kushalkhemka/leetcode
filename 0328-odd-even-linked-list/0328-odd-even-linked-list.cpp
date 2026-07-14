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
    ListNode* oddEvenList(ListNode*& head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head; // single is correct orientation

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* storeEven = even;

        while (even && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            // even we are holding which is odd->next
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = storeEven;

        return head;
    }
};