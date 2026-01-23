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

    int maxElement(vector<int> &nums , int l , int r) {
        int idx = l;

        for(int i=l; i<=r; i++) {
            if(nums[i] > nums[idx]) {
                idx = i;
            }
        }
        return idx;
    }

    TreeNode* buildTree(int left , int right , vector<int> &nums) {
        if(left > right) return nullptr;

        int maxi = maxElement(nums , left , right);

        TreeNode* root = new TreeNode(nums[maxi]);

        root->left = buildTree(left , maxi-1 , nums);
        root->right = buildTree(maxi+1 , right , nums);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();

        return buildTree(0 , n-1 , nums);
    }
};