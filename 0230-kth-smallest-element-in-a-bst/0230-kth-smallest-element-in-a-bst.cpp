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

// //TC->O(N);
// //SC->O(N);
// class Solution {
// public:

//     void solve(TreeNode* root , vector<int> &ans) {
//         if(root == nullptr) return;

//         solve(root->left , ans);
//         ans.push_back(root->val);
//         solve(root->right , ans);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         solve(root , ans);

//         return ans[k-1];
//     }
// };




//TC->O(N);
//SC->O(1);
class Solution {
public:
    int cnt = 0;
    int val = 0;
    void solve(TreeNode* root , int k) {
        if(root == nullptr) return;

        solve(root->left , k);

        cnt++;
        if(cnt == k) {
            val = root->val;
            return;
        }

        solve(root->right , k);
    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root , k);

        return val;
    }
};