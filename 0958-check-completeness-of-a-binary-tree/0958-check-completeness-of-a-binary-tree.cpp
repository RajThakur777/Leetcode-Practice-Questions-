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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool f = false;

        while(!q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node == nullptr) {
                    f = true;
                }
                else {
                    if(f) return false;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};