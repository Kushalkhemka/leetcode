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
struct NodeValue {
    int minVal, maxVal, sum;

    NodeValue(int minVal, int maxVal, int sum)
        : minVal(minVal), maxVal(maxVal), sum(sum) {}
};

class Solution {
public:
    int maxi = 0;

    NodeValue fn(TreeNode* root) {
        if (root == nullptr)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = fn(root->left);
        auto right = fn(root->right);

        // current complete subtree is a BST
        if (root->val > left.maxVal && root->val < right.minVal) {
            int currSum = left.sum + right.sum + root->val;
            maxi = max(maxi, currSum);
            return NodeValue(min(root->val, left.minVal),
                             max(root->val, right.maxVal), currSum);
        }

        return NodeValue(INT_MIN,
                         INT_MAX, // make parent BST condition fail
                         0        //  invalid subtree sum should not be used
        );
    }

    int maxSumBST(TreeNode* root) {
        fn(root);
        return maxi;
    }
};