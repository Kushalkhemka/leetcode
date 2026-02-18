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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root == nullptr)
            return {};
        q.push(root);
        while (!q.empty()) {
            // q.size() jo hogha uss level pe loop kreghe
            int n = q.size();
            vector<int> temp_ans;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                temp_ans.push_back(temp->val);
                if (temp->left) // else
                    q.push(temp->left);
                if (temp->right) // if
                    q.push(temp->right);
            }
            ans.push_back(temp_ans[n - 1]);
        }
        return ans;
    }
};