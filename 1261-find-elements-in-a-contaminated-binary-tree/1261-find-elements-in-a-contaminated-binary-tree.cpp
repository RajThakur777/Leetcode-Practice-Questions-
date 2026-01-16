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
class FindElements {
public:
    unordered_map<int , int> mpp;

    void solve(TreeNode* root) {
        if(root == nullptr) return;

        int x = root->val;

        mpp[x]++;

        if(root->left != nullptr) {
            root->left->val = (2 * x) + 1;
            mpp[((2 * x) + 1)]++;
        }

        if(root->right != nullptr) {
            root->right->val = (2 * x) + 2;
            mpp[((2 * x) + 2)]++;
        }

        solve(root->left);
        solve(root->right);
    }

    FindElements(TreeNode* root) {
        root->val = 0;

        solve(root);
    }
    
    bool find(int target) {    
        if(mpp.find(target) == mpp.end()) return false;

        return true;    
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */