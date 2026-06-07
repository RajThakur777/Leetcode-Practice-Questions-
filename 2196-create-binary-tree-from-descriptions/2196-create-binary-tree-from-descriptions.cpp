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
    void dfs(TreeNode* root , unordered_map<int , vector<pair<int , int>>> &mpp) {
        for(auto it : mpp[root->val]) {
            int child = it.first;
            int isLeft = it.second;

            if(isLeft == 1) {
                root->left = new TreeNode(child);
                dfs(root->left , mpp);
            }
            else {
                root->right = new TreeNode(child);
                dfs(root->right , mpp);
            }    
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , vector<pair<int , int>>> mpp;

        set<int> s1;
        set<int> s2;

        for(int i=0; i<descriptions.size(); i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            mpp[parent].push_back({child , isLeft});

            s1.insert(parent);
            s1.insert(child);
            s2.insert(child);
        }

        int root = -1;
        for(auto it : s1) {
            if(s2.find(it) == s2.end()) {
                root = it;
                break;
            }
        }

        TreeNode* node = new TreeNode(root);

        dfs(node , mpp);

        return node;
    }
};