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
    vector<vector<int>> verticalTraversal(TreeNode* root) { 
        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0 , 0}});
        vector<vector<int>> ans;

        map<int , map<int , multiset<int>>> mpp;

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mpp[vertical][level].insert(node->val);

            if(node->left != nullptr) {
                q.push({node->left , {vertical - 1 , level + 1}});
            }

            if(node->right != nullptr) {
                q.push({node->right , {vertical + 1 , level + 1}});
            }
        }  

        for(auto p : mpp) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};