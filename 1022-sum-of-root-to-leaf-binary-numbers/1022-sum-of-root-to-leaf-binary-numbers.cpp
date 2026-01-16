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

    void dfs(TreeNode* root , vector<string> &vec , string &str) {
        if(root == nullptr) return;

        str += (to_string(root->val));

        if(root->left == nullptr && root->right == nullptr) {
            vec.push_back(str);
        }

        dfs(root->left , vec , str);
        dfs(root->right , vec , str);

        str.pop_back();
    }

    int binToDec(string str) {
        int p = 0;

        int number = 0;
        for(int i=str.size()-1; i>=0; i--) {
            number += ((str[i] - '0') * pow(2 , p));
            p++;
        }
        return number;
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> vec;

        string str;
        dfs(root , vec , str);

        int sum = 0;
        for(int i=0; i<vec.size(); i++) {
            sum += binToDec(vec[i]);
        }
        return sum;
    }
};