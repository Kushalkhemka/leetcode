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
    int res=0;
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;            
        }
        return max(height(root->left),height(root->right))+1; 
    }
    void diameter(TreeNode* root) {
        if(root==nullptr) return;
        int left=height(root->left);
        int right=height(root->right);

        res=max(res,left+right);
        diameter(root->left); 
        diameter(root->right); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        diameter(root);
        return res;
    }


};