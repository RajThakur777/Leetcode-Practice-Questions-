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

    int ht(TreeNode* node) {
        if(node == nullptr) return 0;

        int left = ht(node->left);
        int right = ht(node->right);

        ans = max(ans , left + right);

        return 1 + max(left , right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ht(root);

        return ans;
    }
};