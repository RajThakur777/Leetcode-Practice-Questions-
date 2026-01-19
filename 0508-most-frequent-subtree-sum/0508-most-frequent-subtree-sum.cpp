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
    unordered_map<int , int> mpp;

    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int value = left + right + root->val;
        mpp[value]++;

        return left + right + root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {   
        dfs(root);

        vector<int> ans;

        int maxi = 0;

        for(auto it : mpp) {
            maxi = max(maxi , it.second);
        }

        for(auto it : mpp) {
            if(it.second == maxi) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};