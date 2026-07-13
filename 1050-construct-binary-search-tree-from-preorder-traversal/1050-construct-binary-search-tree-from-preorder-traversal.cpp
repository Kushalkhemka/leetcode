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
    TreeNode* constructBST(vector<int>& preorder, int preStart, int preEnd) {
        if (preStart > preEnd)
            return nullptr;
        // loop from preStart to PreEnd inclusively and find the bound to divide
        // further
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root; // ye upar jaake jud jaeghi
        }
        // now check the idx via looping
        int i;
        for (i = preStart + 1; i <= preEnd;) {
            if (preorder[i] > preorder[preStart]) {
                break;
            }
            i++;
        }
        int numOfElements =
            i - preStart - 1; //-1 not +1 becaue i is already +1 ahead pointing
                              // at element greater than the root node
        root->left =
            constructBST(preorder, preStart + 1, preStart + numOfElements);
        root->right =
            constructBST(preorder, preStart + numOfElements + 1, preEnd);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // your code goes here
        return constructBST(preorder, 0, preorder.size() - 1);
    }
};