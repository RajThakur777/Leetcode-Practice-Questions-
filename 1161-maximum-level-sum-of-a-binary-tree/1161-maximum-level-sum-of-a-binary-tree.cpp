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
    int maxLevelSum(TreeNode* root) {
        map<int , vector<int>> mpp;
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }

                sum += node->val;
            }
            mpp[sum].push_back(level);
            level++;
        }

        int maxi = INT_MIN;
        for(auto it : mpp) {
            maxi = max(maxi , it.first);
        }

        int ans = 0;
        for(auto it : mpp) {
            if(it.first == maxi) {
                vector<int> v = it.second;
                ans = v[0];
                break;
            }
        }
        return ans;
    }
};