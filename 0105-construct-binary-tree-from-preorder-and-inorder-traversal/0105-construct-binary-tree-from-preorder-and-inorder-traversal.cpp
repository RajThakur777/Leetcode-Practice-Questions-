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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder , int st , int ed , int &idx) {
        if(st > ed) {
            return nullptr;
        }

        int rootVal = preorder[idx];

        int i = st;

        for(; i<inorder.size(); i++) {
            if(inorder[i] == rootVal) {
                break;
            }
        }

        idx++;

        TreeNode* root = new TreeNode(rootVal);

        root->left = build(preorder , inorder , st , i - 1 , idx);
        root->right = build(preorder , inorder , i + 1 , ed , idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        int idx = 0;

        return build(preorder , inorder , 0 , n-1 , idx);
    }
};