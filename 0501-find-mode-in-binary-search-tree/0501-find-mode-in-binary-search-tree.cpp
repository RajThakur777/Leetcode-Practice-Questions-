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

    void solve(TreeNode* root , unordered_map<int , int> &mpp) {
        if(root == nullptr) return;

        mpp[root->val]++;

        solve(root->left , mpp);
        solve(root->right , mpp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int , int> mpp;

        solve(root , mpp);

        int maxi = INT_MIN;
        for(auto it : mpp) {
            maxi = max(maxi , it.second);
        }

        vector<int> ans;
        for(auto it : mpp) {
            if(maxi == it.second) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};