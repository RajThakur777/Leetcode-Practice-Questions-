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

    bool solve(TreeNode* root , set<int> &st , int k) {
        if(root == nullptr) return false;

        if(st.find(k - root->val) != st.end()) {
            return true;
        }

        st.insert(root->val);
        return solve(root->left , st , k) || solve(root->right , st , k);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> st;

        return solve(root , st , k);
    }
};