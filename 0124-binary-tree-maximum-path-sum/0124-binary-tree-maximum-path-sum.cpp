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
    int ans = INT_MIN;

    int func(TreeNode* node) {
        if(node == nullptr) return 0;

        int leftSum = max(0 , func(node->left));
        int rightSum = max(0 , func(node->right));

        ans = max(ans , leftSum + rightSum + node->val);

        return max(leftSum , rightSum) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        func(root);

        return ans;
    }
};