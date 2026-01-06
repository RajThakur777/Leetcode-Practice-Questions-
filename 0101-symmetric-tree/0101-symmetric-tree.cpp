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

    bool isSymmetricUtil(TreeNode* p , TreeNode* q) {
        if(p == nullptr || q == nullptr) return (p == q);

        return (p->val == q->val) && (isSymmetricUtil(p->left , q->right) && isSymmetricUtil(p->right , q->left));
    }

    bool isSymmetric(TreeNode* root) {
        return (root == nullptr) || (isSymmetricUtil(root->left , root->right));
    }
};