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

    int convert(string res) {
        int num = 0;

        int idx = 0;

        for(int i=res.size()-1; i>=0; i--) {
            if(res[i] == '1') {
                num += pow(2 , idx);
            }
            idx++;
        }
        return num;
    }

    void solve(TreeNode* root , string res , vector<string> &ans) {
        if(root == nullptr) {
            return;
        }

        res += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(res);
            return;
        }

        solve(root->left , res , ans);
        solve(root->right , res , ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> ans;

        string res = " ";

        solve(root , res , ans);

        int sum = 0;

        for(auto it : ans) {
            int val = convert(it);
            sum += val;
        }
        return sum;
    }
};