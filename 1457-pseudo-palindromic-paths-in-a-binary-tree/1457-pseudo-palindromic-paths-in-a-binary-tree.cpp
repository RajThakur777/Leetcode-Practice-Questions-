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
    int cnt = 0;

    bool isPalindromic(vector<int> freq) {
        int odd = 0;

        for(int i=1; i<=9; i++) {
            if(freq[i] % 2 != 0) {
                odd++;
            }
        }

        if(odd > 1) return false;

        return true;
    }

    void dfs(TreeNode* root , vector<int> freq) {
        if(root == nullptr) return;

        freq[root->val]++;

        if(root->left == nullptr && root->right == nullptr) {
            if(isPalindromic(freq)) {
                cnt++;
            }
            return;
        }

        dfs(root->left , freq);
        dfs(root->right , freq);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10 , 0);

        dfs(root , freq);

        return cnt;
    }
};