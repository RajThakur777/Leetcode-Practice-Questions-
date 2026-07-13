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
    map<int , int> mpp;
    bool f = false;

    void solve(TreeNode* root , int k) {
        if(!root) {
            return;
        }

        int value = k - (root->val);
        if(mpp.find(value) != mpp.end()) {
            f = true;
            return;
        }

        mpp[root->val]++;

        solve(root->left , k);
        solve(root->right , k);
    }

    bool findTarget(TreeNode* root, int k) {
        solve(root , k);

        return f;
    }
};