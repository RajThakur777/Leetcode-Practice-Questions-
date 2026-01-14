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

    vector<TreeNode*> build(int st , int ed) {
        vector<TreeNode*> ans;

        if(st > ed) {
            ans.push_back(nullptr);
            return ans;
        }

        if(st == ed) {
            TreeNode* root = new TreeNode(st);
            ans.push_back(root);
            return ans;
        }

        for(int i=st; i<=ed; i++) {
            vector<TreeNode*> left = build(st , i - 1);
            vector<TreeNode*> right = build(i + 1 , ed);

            for(int j=0; j<left.size(); j++) {
                for(int k=0; k<right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1 , n);
    }
};