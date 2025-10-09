class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // CHANGED: Added edge case for empty or single-node lists.

        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> ans;
        while (fast != nullptr && fast->next != nullptr) {
            ans.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // After the loop, `slow` is at the start of the second half.
        // If the list was odd, we need to skip the middle element.
        if (fast != nullptr) { // CHANGED: This check correctly identifies an odd-length list.
            slow = slow->next;   // CHANGED: Skip the middle element *before* the loop.
        }

        // Now, `slow` is correctly positioned. We can use a single comparison loop.
        while (slow != nullptr) { // CHANGED: Simplified comparison loop.
            int lastElem = ans.top();
            ans.pop();
            if (lastElem != slow->val) { // CHANGED: More direct comparison.
                return false;
            }
            slow = slow->next;
        }

        return true;
    }
};