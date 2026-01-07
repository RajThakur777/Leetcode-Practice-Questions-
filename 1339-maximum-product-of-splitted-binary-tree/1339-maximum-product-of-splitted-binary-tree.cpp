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

    const int mod = 1e9 + 7;
    #define ll long long 

    ll findSum(TreeNode* root) {
        if(root == nullptr) return 0;

        ll left = findSum(root->left);
        ll right = findSum(root->right);

        return left + right + root->val;
    }

    ll ans = LLONG_MIN;

    ll solve(TreeNode* root , ll &total) {
        if(root == nullptr) {
            return 0;
        }

        ll left = solve(root->left , total);
        ll right = solve(root->right , total);

        ll value = left + right + root->val;
        ll res = (total - value) * (value);

        ans = max(ans , res);

        return value;
    }

    int maxProduct(TreeNode* root) {
        ll total = findSum(root);

        solve(root , total);

        return ans % mod;
    }
};