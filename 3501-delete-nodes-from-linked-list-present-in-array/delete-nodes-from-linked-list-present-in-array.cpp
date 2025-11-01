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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == nullptr)
            return nullptr;

        // make a hashmap of nums value
        unordered_set<int> hashmap;
         for (int i = 0; i < nums.size(); i++) {
            hashmap.insert(nums[i]);
        }

        //get the head first which needs to be return
        
        // iterate LL
        ListNode* HEAD = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int flag=0;
        while (curr->next!= nullptr) {
            if (hashmap.find(curr->val) != hashmap.end()) {
                // mean exists so remove it
                if(HEAD==nullptr){
                    prev=curr;
                    curr=curr->next;
                }
                else{
                    prev->next=curr->next;
                    curr=curr->next;
                }
            }
            else{
                if(HEAD==nullptr) HEAD=curr;
                prev=curr; curr=curr->next; 
            }
        }
        //if need to remove last node then do
        if (hashmap.find(curr->val) != hashmap.end()) {
            prev->next=nullptr;
        }
        return HEAD?HEAD:curr;
    }
};