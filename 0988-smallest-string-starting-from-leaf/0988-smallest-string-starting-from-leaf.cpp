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
    void dfs(TreeNode* root , vector<string> &vec , string s) {
        if(root == nullptr) return;

        char ch = root->val + 'a';
        s.push_back(ch);

        if(root->left == nullptr && root->right == nullptr) {
            reverse(s.begin() , s.end());
            vec.push_back(s);
        }

        dfs(root->left , vec , s);
        dfs(root->right , vec , s);
    }
 
    string smallestFromLeaf(TreeNode* root) {
        vector<string> vec;

        string s;
        dfs(root , vec , s);

        sort(vec.begin() , vec.end());

        return vec[0];
    }
};