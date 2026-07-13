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

#pragma GCC optimize("Ofast")
#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void* operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void*>(&BUFFER[pos - size]);
}

void* operator new[](const std::size_t size) { return operator new(size); }

void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, std::size_t) noexcept {}
void operator delete[](void*, std::size_t) noexcept {}
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            // jaha nullptr mila waha end because if thread bi ni h and curr
            // khud null hogya to fir end hi h

            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right; // move to right tree to apply this logic
                                    // now there
            } else {
                TreeNode* prev = curr;
                prev = prev->left;
                while (prev->right != nullptr && prev->right != curr) {
                    // prev->right!=curr is to check for the thread if exists
                    // prev->right==nullptr this is to move to the end of node
                    // of that subtree to make the thread
                    prev = prev->right;
                }

                // now we have the node
                if (prev->right == nullptr) {
                    // make the thread
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // dubara aaya h mtlb
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* node) {
        stack<TreeNode*> st;
        vector<int> ans;

        while (true) {
            if (node != nullptr) {
                // push to stack and move left
                st.push(node);
                node = node->left;
            }
            // if node is nullptr then we move back and then move to right
            else {
                // when coming back
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    void fn(TreeNode* root, vector<int>& ans) {
        if (root->right == nullptr && root->left == nullptr) {
            ans.push_back(root->val);
            return;
        }

        // left
        if (root->left != nullptr)
            fn(root->left, ans);
        // beech wala
        ans.push_back(root->val);
        // right
        if (root->right != nullptr)
            fn(root->right, ans);
    }
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        fn(root, ans);
        return ans;
    }
};
