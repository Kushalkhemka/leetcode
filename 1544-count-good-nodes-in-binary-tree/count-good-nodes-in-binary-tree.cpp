/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count;
    void fn(TreeNode* root, int max_val){
        if(root==nullptr) return;
        if(root->val>=max_val) count++;
        fn(root->left,max(root->val,max_val));
        fn(root->right,max(root->val,max_val));
    }
    int goodNodes(TreeNode* root) {
        fn(root,INT_MIN);
        return count;
    }
};