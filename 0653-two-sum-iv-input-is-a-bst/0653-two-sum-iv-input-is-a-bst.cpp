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
    vector<int> inorder(TreeNode* node) {
        stack<TreeNode*> st;
        vector<int> ans;

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
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans = inorder(root);

        int i = 0;
        int n = ans.size();
        int j = n - 1;

        while (i < j) {
            // ans is sorted as bst inorder is ascending order sorted (strictly
            // increasing although)
            int sum = ans[i] + ans[j];
            if (sum == k)
                return true;
            else if (sum > k) {
                // move the j left
                j--;
            } else {
                // sum is less than k
                i++;
            }
        }

        return false;
    }
};