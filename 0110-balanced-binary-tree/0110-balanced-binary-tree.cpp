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

    int ht(TreeNode* node) {
        if(node == nullptr) return 0;

        int left = ht(node->left);
        int right = ht(node->right);

        if(left == -1 || right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(ht(node->left) , ht(node->right));
    }

    bool isBalanced(TreeNode* root) {
        return ht(root) != -1;
    }
};