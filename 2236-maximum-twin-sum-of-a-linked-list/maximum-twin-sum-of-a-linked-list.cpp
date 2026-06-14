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
    int pairSum(ListNode* head) {
        //easy shit nipta dungha haha
        ListNode* temp=head;
        int n=0;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        vector<int>v(n/2);
        int i=0;
        temp=head;
        while(i<n/2){
            v[i]=temp->val;
            temp=temp->next;i++;
        }
        i=n/2-1;
        while(i>=0){
            v[i]+=temp->val;
            temp=temp->next;i--;
        }
        return *max_element(v.begin(),v.end());
    }
};