/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void buildGraph(TreeNode* root , TreeNode* parent , unordered_map<int , vector<int>> &mpp) {
        if(root == nullptr) return;

        if(parent) {
            mpp[parent->val].push_back(root->val);
            mpp[root->val].push_back(parent->val);
        }

        buildGraph(root->left , root , mpp);
        buildGraph(root->right , root , mpp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        unordered_map<int , vector<int>> mpp;

        buildGraph(root , nullptr , mpp);  

        queue<int> q;
        set<int> st;

        int level = 0;

        q.push(target->val);
        st.insert(target->val);

        bool f = false;

        if(k == 0) return {target->val};

        vector<int> ans;

        while(!q.empty() && !f) {
            int sz = q.size();
            bool vis = false;

            for(int i=0; i<sz; i++) {
                int node = q.front();
                q.pop();

                if(level + 1 == k) {
                    for(auto it : mpp[node]) {
                        if(!st.count(it)) {
                           st.insert(it);
                           q.push(it);
                           ans.push_back(it);
                           f = true;
                           vis = true;
                        }
                    } 
                }
                else {
                    for(auto it : mpp[node]) {
                        if(!st.count(it)) {
                           st.insert(it);
                           q.push(it);
                           vis = true;
                        }
                    }
                }
            }
            if(vis) {
                level++;
            }

            if(f) break;
        }
        return ans;
    }
};