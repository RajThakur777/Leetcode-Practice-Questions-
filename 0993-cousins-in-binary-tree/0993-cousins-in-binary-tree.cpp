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
    unordered_map<int , pair<int , int>> mpp;

    void dfs(TreeNode* root , int parent , int level) {
        if(root == nullptr) return;

        mpp[root->val] = {parent , level};

        dfs(root->left , root->val , level + 1);
        dfs(root->right , root->val , level + 1);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root , -1 , 0);

        int p_x = 0;
        int l_x = 0;
        int p_y = 0;
        int l_y = 0;

        for(auto it : mpp) {
            if(it.first == x) {
                p_x = it.second.first;
                l_x = it.second.second;
            }
            else if(it.first == y) {
                p_y = it.second.first;
                l_y = it.second.second;
            }
        }

        if((p_x != p_y) && (l_x == l_y)) return true;

        return false;
    }
};