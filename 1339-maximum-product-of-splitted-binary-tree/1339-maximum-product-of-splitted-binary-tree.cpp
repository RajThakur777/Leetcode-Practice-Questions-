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
    #define ll long long
    const int mod = 1e9 + 7;

    ll maxi = 0;

    ll totalSum(TreeNode* root) {
        if(root == nullptr) return 0;

        ll left = totalSum(root->left);
        ll right = totalSum(root->right);

        return left + right + root->val;
    }

    ll dfs(TreeNode* root , ll &total) {
        if(root == nullptr) return 0;

        ll left = dfs(root->left , total);
        ll right = dfs(root->right , total);

        ll value = left + right + root->val;

        maxi = max(maxi , ((value) * 1LL * (total - value)));

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        ll total = totalSum(root);

        dfs(root , total);

        return maxi % mod;
    }
};