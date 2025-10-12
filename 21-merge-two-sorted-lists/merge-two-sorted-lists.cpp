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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        
        ListNode* pt1 = list1;
        ListNode* pt3 = list2;
        // ListNode* pt2=pt1->next; // This lookahead is not needed. We will repurpose pt2.
        // ListNode* pt4=pt3->next; // This lookahead is not needed.
        ListNode* oldhead = nullptr;
        ListNode* pt2 = nullptr; // RE-PURPOSED: pt2 will now act as the TAIL of the merged list.

        // Step 1: Correctly decide the head of the merged list.
        if(pt1->val <= pt3->val) { // CHANGED: Compare heads of list1 and list2, not nodes within list1.
            oldhead = pt1;
            pt2 = oldhead; // The head is also the first tail.
            pt1 = pt1->next;
        } else {
            oldhead = pt3;
            pt2 = oldhead; // The head is also the first tail.
            pt3 = pt3->next;
        }

        // Step 2: Loop while both lists still have nodes.
        while(pt1 != nullptr && pt3 != nullptr) { // CHANGED: Loop condition now correctly checks the heads of remaining lists.
            if(pt1->val <= pt3->val){
                pt2->next = pt1; // NON-DESTRUCTIVE: Append pt1 to the tail.
                pt2 = pt2->next; // Move the tail forward.
                pt1 = pt1->next; // Advance pt1.
            } else {
                pt2->next = pt3; // NON-DESTRUCTIVE: Append pt3 to the tail.
                pt2 = pt2->next; // Move the tail forward.
                pt3 = pt3->next; // Advance pt3.
            }
        }
        // CHANGED: The entire loop logic is new. It safely appends the smaller node to the
        // end of the merged list (pointed to by pt2) and advances the pointers.

        // Step 3: Attach the remainder of the non-empty list.
        if (pt1 != nullptr) { // ADDED: This is a crucial new step.
            pt2->next = pt1;
        } else {
            pt2->next = pt3;
        }

        return oldhead;
    }
};