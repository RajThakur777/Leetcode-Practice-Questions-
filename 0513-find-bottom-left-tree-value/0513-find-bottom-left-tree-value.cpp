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
    int ans = -1;
    int maxDepth = -1;

    void solve(TreeNode* root , int d) {
        if(root == nullptr) return;

        if(d > maxDepth) {
            maxDepth = d;
            ans = root->val;
        }

        solve(root->left , d + 1);
        solve(root->right , d + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        solve(root , 0);

        return ans;
    }
};