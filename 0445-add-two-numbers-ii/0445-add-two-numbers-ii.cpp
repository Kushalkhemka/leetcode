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
    ListNode* addTwoNum(ListNode*& linkedList1, ListNode*& linkedList2) {
        ListNode* curr1 = linkedList1;
        ListNode* curr2 = linkedList2;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (curr1 != nullptr || curr2 != nullptr || carry) {
            // int a=(curr1)?curr1->data:0;
            // int b=(curr2)?curr2->data:0;
            // curr1=curr1->next; curr2=curr2->next;
            int a = 0;
            int b = 0;
            if (curr1) {
                a = curr1->val;
                curr1 = curr1->next;
            }

            if (curr2) {
                b = curr2->val;
                curr2 = curr2->next;
            }
            int output = a + b + carry; // max value 19 (9+9+1) carry=1 or 0
            carry = output / 10;        // MSB
            int sum = output % 10;      // LSB
            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        return dummy->next;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* nxt = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;

        while (nxt) {
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
            prev = curr;
        }

        return curr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1head = reverseList(l1);
        ListNode* l2head = reverseList(l2);
        return reverseList(addTwoNum(l1head, l2head));
    }
};