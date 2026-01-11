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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder , int pSt , int pEd , int iSt , int iEd , unordered_map<int , int> &mpp) {
        if(pSt > pEd || iSt > iEd) return nullptr;

        TreeNode* root = new TreeNode(preorder[pSt]);

        int root_idx = mpp[root->val];
        int left = root_idx - iSt;

        root->left = build(preorder , inorder , pSt + 1 , pSt + left , iSt , root_idx - 1 , mpp);

        root->right = build(preorder , inorder , pSt + left + 1 , pEd , root_idx + 1 , iEd , mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> mpp;

        int n = preorder.size();

        for(int i=0; i<inorder.size(); i++) {
            mpp[inorder[i]] = (i);
        }

        TreeNode* root = build(preorder , inorder , 0 , n - 1 , 0 , n - 1 , mpp);

        return root;
    }
};