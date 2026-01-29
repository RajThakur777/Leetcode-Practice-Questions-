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

    vector<int> bfs(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty()) {
            int sz = q.size();

            int sum = 0;
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }

    void dfs(TreeNode* root , int level , vector<int> &arr) {
        if(root == nullptr) return;

        int l = level + 1;
        int total = (l < arr.size() ? arr[l] : 0);
        int siblingSum = ((root->left != nullptr) ? root->left->val : 0) + ((root->right != nullptr) ? root->right->val : 0);

        if(root->left != nullptr) {
            root->left->val = (total - siblingSum);
        }

        if(root->right != nullptr) {
            root->right->val = (total - siblingSum);
        }

        dfs(root->left , level + 1 , arr);
        dfs(root->right , level + 1 , arr);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> arr = bfs(root);

        dfs(root , 0 , arr);

        root->val = 0;
        
        return root;
    }
};