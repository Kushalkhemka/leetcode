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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            // jaha nullptr mila waha end because if thread bi ni h and curr
            // khud null hogya to fir end hi h

            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right; // move to right tree to apply this logic
                                    // now there
            } else {
                TreeNode* prev = curr;
                prev = prev->left;
                while (prev->right != nullptr && prev->right != curr) {
                    // prev->right!=curr is to check for the thread if exists
                    // prev->right==nullptr this is to move to the end of node
                    // of that subtree to make the thread
                    prev = prev->right;
                }

                // now we have the node
                if (prev->right == nullptr) {
                    // make the thread
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // dubara aaya h mtlb
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};