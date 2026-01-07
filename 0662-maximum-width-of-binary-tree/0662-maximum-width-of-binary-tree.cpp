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
    int widthOfBinaryTree(TreeNode* root) {  
        if(root == nullptr) return 0;

        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});

        long long ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            long long mini = q.front().second;

            long long f,l;

            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second - mini;
                q.pop();

                if(i == 0) {
                    f = idx;
                }

                if(i == sz-1) {
                    l = idx;
                }

                if(node->left != nullptr) {
                    q.push({node->left , 2 * idx + 1});
                }

                if(node->right != nullptr) {
                    q.push({node->right , 2 * idx + 2});
                }
            }
            ans = max(ans , l - f + 1);
        } 
        return (int)ans;
    }
};