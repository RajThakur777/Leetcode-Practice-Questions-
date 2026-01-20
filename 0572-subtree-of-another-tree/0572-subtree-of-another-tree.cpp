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

    bool isSame(TreeNode* root , TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;

        if(root == nullptr || subRoot == nullptr) return false;

        if(root->val != subRoot->val) return false;

        return isSame(root->left , subRoot->left) && isSame(root->right , subRoot->right);
    }

    bool solve(TreeNode* root , TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;

        if(root == nullptr || subRoot == nullptr) return false;      

        if(root->val == subRoot->val) {
            return isSame(root , subRoot) || solve(root->left , subRoot) || solve(root->right , subRoot);
        }
        else {
            return solve(root->left , subRoot) || solve(root->right , subRoot);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root , subRoot);
    }
};