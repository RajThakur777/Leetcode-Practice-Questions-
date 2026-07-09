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

    bool solve(TreeNode* n1 , TreeNode* n2) {
        if(!n1 && !n2) {
            return true;
        }

        if(!n1 || !n2) {
            return false;
        }

        if(n1->val != n2->val) {
            return false;
        }

        return solve(n1->left , n2->right) && solve(n1->right , n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }

        if(!root->left && !root->right) {
            return true;
        }

        if(!root->left || !root->right) {
            return false;
        }

        return solve(root->left , root->right);
    }
};