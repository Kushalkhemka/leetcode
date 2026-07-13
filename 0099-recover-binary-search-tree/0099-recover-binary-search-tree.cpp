/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> inorder(TreeNode* node) {
        stack<TreeNode*> st;
        vector<TreeNode*> ans;

        while (true) {
            if (node != nullptr) {
                // push to stack and move left
                st.push(node);
                node = node->left;
            }
            // if node is nullptr then we move back and then move to right
            else {
                // when coming back
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node);
                node = node->right;
            }
        }

        return ans;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans = inorder(root);
        int n = ans.size();
        // not sorted inorder but must be sorted
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        for (int i = 0; i < n - 1; i++) {
            if (ans[i]->val > ans[i + 1]->val) {
                // violation happened check if its first violation or later than
                // first
                if (first == nullptr) {
                    // update both first as in case of adjacent elements only
                    // one violation can be observed so we assume earlier and
                    // later if we get one more violation then it means it is
                    // the CASE 2 of non adjacent
                    first = ans[i];
                    second = ans[i + 1];
                } else {
                    // non adj case
                    second = ans[i + 1];
                }
            }
        }
        if (first == nullptr || second == nullptr)
            return;
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return;
    }
};