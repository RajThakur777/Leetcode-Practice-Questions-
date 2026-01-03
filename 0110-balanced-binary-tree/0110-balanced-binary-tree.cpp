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

        return 1 + max(ht(node->left) , ht(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int left = ht(root->left);
        int right = ht(root->right);

        if(abs(left - right) > 1) {
            return false;
        }

        bool l1 = isBalanced(root->left);
        bool l2 = isBalanced(root->right);

        if(!l1 || !l2) return false;

        return true;
    }
};