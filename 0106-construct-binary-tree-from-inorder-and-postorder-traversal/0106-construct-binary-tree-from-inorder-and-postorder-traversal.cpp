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

    TreeNode* solve(vector<int>& inorder , vector<int>& postorder , int postLeft , int postRight , int inLeft , int inRight , map<int , int> &mpp) {
        if(postLeft > postRight || inLeft > inRight) {
            return nullptr;
        }

        int idx = mpp[postorder[postRight]];

        TreeNode* root = new TreeNode(postorder[postRight]);

        root->left = solve(inorder , postorder , postLeft , postLeft + (idx - inLeft - 1) , inLeft , idx - 1 , mpp);
        root->right = solve(inorder , postorder , postLeft + (idx - inLeft) , postRight - 1 , idx + 1 , inRight , mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        return solve(inorder , postorder , 0 , n-1 , 0 , n-1 , mpp);
    }
};