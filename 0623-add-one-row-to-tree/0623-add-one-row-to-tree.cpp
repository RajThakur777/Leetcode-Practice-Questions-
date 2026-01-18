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
    void dfs(TreeNode* root , int val , int d) {
        if(root == nullptr) return;

        if(d == 1) {
            TreeNode* newNode1 = new TreeNode(val);
            TreeNode* newNode2 = new TreeNode(val);
            TreeNode* left = (root->left) == nullptr ? nullptr : root->left;
            TreeNode* right = (root->right) == nullptr ? nullptr : root->right;

            root->left = newNode1;
            root->right = newNode2;

            newNode1->left = left;
            newNode2->right = right;
        }

        dfs(root->left , val , d-1);
        dfs(root->right , val , d-1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);

            newRoot->left = root;

            return newRoot;
        }

        dfs(root , val , depth - 1);

        return root;
    }
};