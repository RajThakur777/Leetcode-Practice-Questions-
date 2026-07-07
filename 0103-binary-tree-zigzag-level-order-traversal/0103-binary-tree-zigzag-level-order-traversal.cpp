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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;

        while(!q.empty()) {
            int n = q.size();

            vector<int> res;

            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();

                res.push_back(node->val);

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if(level % 2 == 0) {
                ans.push_back(res);
            }
            else {
                reverse(res.begin() , res.end());

                ans.push_back(res);
            }

            level++;
        }

        return ans;
    }
};