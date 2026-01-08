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
    void buildGraph(TreeNode *node, TreeNode *parent, unordered_map<int, vector<int>> &mpp) {
        if (node == nullptr)
            return;

        if(parent) {
            mpp[node->val].push_back(parent->val);
            mpp[parent->val].push_back(node->val);
        }

        buildGraph(node->left, node, mpp);
        buildGraph(node->right, node, mpp);
    }

    int amountOfTime(TreeNode* root, int start) {  
        unordered_map<int , vector<int>> mpp;

        buildGraph(root , nullptr , mpp);

        unordered_set<int> st;
        queue<int> q;
        q.push(start);
        st.insert(start);

        int time = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool infected = false;

            for(int i=0; i<sz; i++) {
                int node = q.front();
                q.pop();

                for(auto it : mpp[node]) {
                    if(!st.count(it)) {
                        st.insert(it);
                        q.push(it);
                        infected = true;
                    }
                }
            }
            if(infected) time++;
        }
        return time;
    }
};