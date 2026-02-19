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
    int result=-1;
    void inorder(TreeNode* node,int& count){
        if(result!=-1) return;
        if(node==nullptr) return;
        inorder(node->left,count);
        count--;
        if(count==0) result=node->val;
        inorder(node->right,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        //very easy -> inorder traversal of the BST is sorted
        inorder(root,k);
        return result;
    }
};