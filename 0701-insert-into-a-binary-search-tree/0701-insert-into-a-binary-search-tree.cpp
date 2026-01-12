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

    TreeNode* solve(TreeNode* root , int val , TreeNode* parent) {
        if(root == nullptr) return parent;

        if(root->val > val) {
            return solve(root->left , val , root);
        }
        else {
            return solve(root->right , val , root);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        TreeNode* node = solve(root , val , nullptr);

        if(node->val > val) {
            node->left = new TreeNode(val);
        }
        else {
            node->right = new TreeNode(val);  
        }
        return root;
    }
};