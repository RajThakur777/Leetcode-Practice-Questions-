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
    int ans = 0;

    void dfs(TreeNode* root , TreeNode* parent , TreeNode* grandParent) {
        if(root == nullptr) return;

        if(grandParent != nullptr && grandParent->val % 2 == 0) {
            ans += root->val;
        }

        dfs(root->left , root , parent);
        dfs(root->right , root , parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root , nullptr , nullptr);

        return ans;
    }
};