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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head; ListNode* slow=head; ListNode* oldHead=head;
        //handle edge cases
        if(head->next==nullptr) return nullptr;
        for(int i=0; i<n;i++){ //advance fast pointer k (n) times
            fast=fast->next;
        }
        if (fast == nullptr) { // CHANGED: Added check to handle removing the head node.
            ListNode* newHead = head->next;
            delete head; // Optional: free memory
            return newHead;
        }

        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        //the slow pointer -> next is the one to delete now delete
        //we have hold of its previous node so
        
        slow->next=slow->next->next;
        
        return oldHead;
    }
};