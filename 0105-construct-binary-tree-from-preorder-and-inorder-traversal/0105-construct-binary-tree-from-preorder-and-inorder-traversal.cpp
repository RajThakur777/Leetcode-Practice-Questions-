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

    TreeNode* solve(vector<int>& preorder , vector<int>& inorder , int preLeft , int preRight , int inLeft , int inRight , map<int , int> &mpp) {
        if(preLeft > preRight || inLeft > inRight) {
            return nullptr;
        }

        int idx = mpp[preorder[preLeft]];

        TreeNode* root = new TreeNode(inorder[idx]);

        root->left = solve(preorder , inorder , preLeft + 1 , preLeft + (idx - inLeft) , inLeft , idx - 1 , mpp);
        root->right = solve(preorder , inorder , preLeft + (idx - inLeft + 1) , preRight , idx + 1 , inRight , mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[inorder[i]] = i;
        }

        return solve(preorder , inorder , 0 , n-1 , 0 , n-1 , mpp);
    }
};