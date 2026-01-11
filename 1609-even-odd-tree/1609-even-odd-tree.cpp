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

    bool increasing(vector<int> &even) {
        for(int i=0; i<even.size(); i++) {
            if(even[i] % 2 == 0) {
                return false;
            }
            else if((i+1 < even.size()) && even[i] >= even[i+1]) {
                return false;
            }
        }
        return true;
    }

    bool decreasing(vector<int> &odd) {
        for(int i=0; i<odd.size(); i++) {
            if(odd[i] % 2 != 0) {
                return false;
            }
            else if((i+1 < odd.size()) && odd[i] <= odd[i+1]) {
                return false;
            }
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);


        int level = 0;

        bool f = true;

        vector<int> even;
        vector<int> odd;

        while(!q.empty()) {
            int sz = q.size();

            bool f1 = true;
            bool f2 = true;

            if(level % 2 == 0) {
                for(int i=0; i<sz; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left != nullptr) {
                       q.push(node->left);
                    }

                    if(node->right != nullptr) {
                       q.push(node->right);
                    }
                    even.push_back(node->val);
                }
            }
            else {
                for(int i=0; i<sz; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left != nullptr) {
                       q.push(node->left);
                    }

                    if(node->right != nullptr) {
                       q.push(node->right);
                    }
                    odd.push_back(node->val);
                }
            }

            if(even.size() > 0) {
                f1 = increasing(even);   
            }

            if(odd.size() > 0) {
                f2 = decreasing(odd);
            }

            if(!f1 || !f2) {
                f = false;
                break;
            }
            level++;
            even.clear();
            odd.clear();
        }
        return f;
    }
};