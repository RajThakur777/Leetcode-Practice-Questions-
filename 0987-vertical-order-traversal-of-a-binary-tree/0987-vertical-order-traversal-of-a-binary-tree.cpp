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
        vector<vector<int>> ans;

        map<int , map<int , multiset<int>>> mpp;

        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0 , 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int idx = it.second.first;
            int level = it.second.second;

            mpp[idx][level].insert(node->val);

            if(node->left != nullptr) {
                q.push({node->left , {idx - 1 , level + 1}});
            }

            if(node->right != nullptr) {
                q.push({node->right , {idx + 1 , level + 1}});
            }
        }

        for(auto it : mpp) {
            vector<int> col;
            for(auto x : it.second) {
                col.insert(col.end() , x.second.begin() , x.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};