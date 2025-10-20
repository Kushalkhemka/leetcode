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
    ListNode* deleteDuplicates(ListNode* head) {
        //just maintain the pointers since the list is sorted maintain the prev current and next
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head; //sorted without duplicate itself
        ListNode* curr=head;
        ListNode* nextPtr=curr->next;
        ListNode* oldHead=head;
        while(nextPtr!=nullptr){
            if(curr->val==nextPtr->val){
                nextPtr=nextPtr->next;
                curr->next=nextPtr;
            }
            else{
                curr=nextPtr;
                nextPtr=nextPtr->next;
            }
        }
        return oldHead;
    }
};