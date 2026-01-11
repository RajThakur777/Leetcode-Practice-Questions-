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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int iSt , int iEd , int pSt , int pEd , unordered_map<int , int> &mpp) {
        if(pSt > pEd || iSt > iEd) return nullptr;

        TreeNode* root = new TreeNode(postorder[pEd]);

        int root_idx = mpp[root->val];
        int left = root_idx - iSt;

        root->left = build(inorder , postorder , iSt , root_idx - 1 , pSt , pSt + left - 1 , mpp);

        root->right = build(inorder , postorder , root_idx + 1 , iEd , pSt + left , pEd - 1 , mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        unordered_map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = build(inorder , postorder , 0 , n-1 , 0 , n-1 , mpp);

        return root;
    }
};