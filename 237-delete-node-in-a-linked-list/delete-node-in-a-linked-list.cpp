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
    void deleteNode(ListNode* node) {
        //swap the values;
     //storing memory address of given node to a pointer
        int value=node->next->val;
        node->next->val=node->val;
        node->val=value;
        //swapping done

        //we still have access to node so
        node->next=node->next->next; //skip the next node

    }
};