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
    int ans = 0;
    int d;

    int maxDepth(TreeNode* node, int depth) {
        if (node == nullptr)
            return depth - 1;

        return max(
            maxDepth(node->left, depth + 1),
            maxDepth(node->right, depth + 1)
        );
    }

    void solve(TreeNode* node, int l) {
        if (node == nullptr) return;

        if (l == d) {
            ans += node->val;
        }

        solve(node->left, l + 1);
        solve(node->right, l + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        d = maxDepth(root, 1);
        solve(root, 1);
        return ans;
    }
};
