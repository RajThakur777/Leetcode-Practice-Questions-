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
    int find(vector<int> res) {
        vector<int> copy = res;

        sort(copy.begin() , copy.end());

        unordered_map<int , int> mpp;
        for(int i=0; i<res.size(); i++) {
            mpp[res[i]] = i;
        }

        int cnt = 0;

        for(int i=0; i<res.size(); i++) {
            if(res[i] != copy[i]) {
                cnt++;
                int idx = mpp[copy[i]];
                mpp[copy[i]] = i;
                mpp[res[i]] = idx;
                swap(res[i] , res[idx]);
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();

            vector<int> res;
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr) {
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    q.push(node->right);
                }

                res.push_back(node->val);
            }

            int ops = find(res);
            ans += ops;
        }
        return ans;
    }
};




//minimum swaps to sort an array in ascending order in one swap you can swap two different elements in the array 