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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            double sz = q.size();

            double val = 0.0;
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }
                val += node->val;
            }

            ans.push_back((val) / (sz));
        }
        return ans;
    }
};