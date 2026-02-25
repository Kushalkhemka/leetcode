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
    int sum = 0;
    string temp;
    int stoi(string s) {
        int x = 0;
        for (char c : s) {
            x = (x << 1) | (c - '0');
        }
        return x;
    }
    void fn(TreeNode* root) {
        if (root == nullptr)
            return;
        temp.push_back(root->val+'0');
        if (root->left == nullptr && root->right == nullptr) {
            sum += stoi(temp);
            temp.pop_back();
            return;
        }
        
        fn(root->left);
        fn(root->right);
        temp.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) { fn(root); return sum; }
};