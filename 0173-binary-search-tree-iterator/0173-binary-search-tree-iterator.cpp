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

class BSTIterator {
public:
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* node;

    BSTIterator(TreeNode* root) { node = root; }

    bool hasNext() { return (!st.empty() || node != nullptr); }

    int next() {
        while (true) {
            if (node != nullptr) {
                // push to stack and move left
                st.push(node);
                node = node->left;
            }
            // if node is nullptr then we move back and then move to right
            else {
                // when coming back
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                int value = node->val;
                node = node->right;
                return value; // we only do one addition and then break
                              // logically
                // since next call is always valid we can assume stack will not
                // be underflow at there always be the next number
            }
        }

        return -1; // unreachable code
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */