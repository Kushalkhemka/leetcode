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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                temp=slow; //save the first meeting point
                break;
            }
        }
        if(temp==nullptr){return nullptr;}
        //reset slow pointer to head
        slow=head;
        //now move both
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow; 

    }
};