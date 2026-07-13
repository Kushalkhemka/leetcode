/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* successor(TreeNode* root) {
        TreeNode* curr = root->right;

        // go left left
        while (curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;

        TreeNode* curr = p;
        if (curr->right != nullptr) {
            return successor(curr);
        }
        curr = root;
        TreeNode* suc = nullptr;
        while (curr) {
            if (curr->val < p->val) {
                curr = curr->right;
            } else if (curr->val > p->val) {
                // go left
                suc = curr;
                curr = curr->left;
            } else {
                // now we have got
                break;
            }
        }

        return (suc != nullptr) ? suc : nullptr;
    }
};