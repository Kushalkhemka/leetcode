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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;              
        q.push(root);

        int maxSoFar = INT_MIN;           
        int ansLevel = 1;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();          
            int tempSum = 0;             
            level++;                      

            for (int i = 0; i < size; i++) {  
                TreeNode* node = q.front();
                q.pop();

                tempSum += node->val;

                if (node->left) q.push(node->left);    
                if (node->right) q.push(node->right);  
            }

            if (tempSum > maxSoFar) {     
                maxSoFar = tempSum;
                ansLevel = level;
            }
        }

        return ansLevel;
    }
};
