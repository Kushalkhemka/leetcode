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
    bool fn(TreeNode* root, long long low, long long high){
        if(root==nullptr) return true;
        //check for the left subtree and the right subtree
        if(root->val<=low || root->val>=high) return false;
        return fn(root->left,low, root->val) && fn(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr) return true;
        return fn(root,LONG_MIN,LONG_MAX);
    }
};