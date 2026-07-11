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

    TreeNode* solve(int preLeft , int preRight , int inLeft , int inRight , vector<int> &preorder , vector<int> &inorder , map<int , int> &mpp) {
        if(preLeft > preRight || inLeft > inRight) {
            return nullptr;
        }

        int root_val = preorder[preLeft];

        int idx = mpp[root_val];

        TreeNode* root = new TreeNode(root_val);

        root->left = solve(preLeft + 1 , preLeft + idx - inLeft , inLeft , idx - 1 , preorder , inorder , mpp);
        root->right = solve(preLeft + idx - inLeft + 1 , preRight , idx + 1 , inRight , preorder , inorder , mpp);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;

        sort(inorder.begin() , inorder.end());

        int n = preorder.size();
        
        map<int , int> mpp;
        for(int i=0; i<inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return solve(0 , n-1 , 0 , n-1 , preorder , inorder , mpp);
    }
};