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
    int ans=INT_MIN;
    int fn(TreeNode* root){
        if(root==nullptr) return 0;

        int leftPathSum=max(fn(root->left),0);
        int rightPathSum=max(fn(root->right),0);

        int totalPathSum=root->val+leftPathSum+rightPathSum;
        ans=max(ans,totalPathSum);
        return root->val+max(leftPathSum, rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        fn(root); return ans;
    }
};