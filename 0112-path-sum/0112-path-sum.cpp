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

    bool solve(TreeNode* root , int sum , int targetSum) {
        if(root == nullptr) return false;

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr) {
            return (sum == targetSum);
        }

        return solve(root->left , sum , targetSum) || solve(root->right , sum , targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) { 
        if(root == nullptr) return false;

        return solve(root , 0 , targetSum);
    }
};