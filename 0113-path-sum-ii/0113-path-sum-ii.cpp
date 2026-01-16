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

    void solve(TreeNode* root , int targetSum , int sum , vector<vector<int>> &res , vector<int> &ans) {
        if(root == nullptr) return;

        sum += root->val;
        ans.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            if(sum == targetSum) {
                res.push_back(ans);
            }
        }

        solve(root->left , targetSum , sum , res , ans);
        solve(root->right , targetSum , sum , res , ans);

        ans.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;

        vector<int> ans;

        solve(root , targetSum , 0 , res , ans);

        return res;
    }
};