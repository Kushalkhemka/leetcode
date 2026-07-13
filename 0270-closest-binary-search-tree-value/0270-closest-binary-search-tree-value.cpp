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
    void fC(TreeNode* root, double key, int& floor, int& ceil) {
        if (root == nullptr)
            return;

        if (root->val == key) {
            floor = root->val;
            ceil = root->val;
            return;
        }

        if (root->val > key) {
            // go left
            // just make the change here
            ceil = root->val;
            return fC(root->left, key, floor, ceil);
        } else {
            // root<key
            floor = root->val;
            return fC(root->right, key, floor, ceil);
        }
        return; // unreachable code haha
    }
    vector<int> floorCeilOfBST(TreeNode* root, double key) {
        // your code goes here
        // min=root->val, max->val
        if (root == nullptr)
            return {-1, -1};
        int floor = -1;
        int ceil = -1;

        fC(root, key, floor, ceil);
        return {floor, ceil};
    }
    int closestValue(TreeNode* root, double target) {
        vector<int> ans = floorCeilOfBST(root, target);

        double diff = INT_MAX;
        double val = -1;
        if (ans[0] == -1)
            return ans[1];
        if (ans[1] == -1)
            return ans[0];

        return abs(target - ans[0]) <= abs(target - ans[1]) ? ans[0] : ans[1];
    }
};
