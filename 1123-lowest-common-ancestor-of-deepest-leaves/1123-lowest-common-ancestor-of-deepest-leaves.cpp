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
    int maxDepth = 0;

    void solve(TreeNode* root , int d) {
        if(root == nullptr) return;

        maxDepth = max(maxDepth , d);

        solve(root->left , d + 1);
        solve(root->right , d + 1);
    }

    TreeNode* lca(TreeNode* root , int maxDepth) {
        if(root == nullptr || maxDepth == 0) {
            return root;
        }

        TreeNode* left = lca(root->left , maxDepth - 1);
        TreeNode* right = lca(root->right , maxDepth - 1);

        if(left == nullptr) {
            return right;
        }
        else if(right == nullptr) {
            return left;
        }
        else {
            return root;
        }
    } 

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = 0;

        solve(root , d);

        return lca(root , maxDepth);
    }
};