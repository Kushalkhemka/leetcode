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
    // int sum = 0;
    // string temp;
    // int stoi(string s) {
    //     int x = 0;
    //     for (char c : s) {
    //         x = (x << 1) | (c - '0');
    //     }
    //     return x;
    // }

    int sum = 0;

    void dfs(TreeNode* node, int cur) {
        if (!node)
            return;

        cur = (cur << 1) | node->val;

        if (!node->left && !node->right) {
            sum += cur;
            return;
        }

        dfs(node->left, cur);
        dfs(node->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};