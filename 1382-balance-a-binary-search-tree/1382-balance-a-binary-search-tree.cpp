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

    void solve(TreeNode* root , vector<int> &ans) {
        if(root == nullptr) return;

        solve(root->left , ans);
        ans.push_back(root->val);
        solve(root->right , ans);
    }

    TreeNode* dfs(vector<int> &ans , int low , int high) {
        if(low > high) return nullptr;

        int mid = (low + high) / 2;

        TreeNode* root = new TreeNode(ans[mid]);

        root->left = dfs(ans , low , mid - 1);
        root->right = dfs(ans , mid + 1 , high);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        
        solve(root , ans);

        return dfs(ans , 0 , ans.size() - 1);
    }
};