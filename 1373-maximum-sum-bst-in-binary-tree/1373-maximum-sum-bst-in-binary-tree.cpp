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
    struct Info {
        bool isBST;
        long long mn;
        long long mx;
        int sum;

        Info(bool isBST, long long mn, long long mx, int sum) {
            this->isBST = isBST;
            this->mn = mn;
            this->mx = mx;
            this->sum = sum;
        }
    };

    int maxSum = 0;

    Info isBST(TreeNode* root) {
        if (root == nullptr) {
            return Info(true, LLONG_MAX, LLONG_MIN, 0);
        }

        Info leftInfo = isBST(root->left);
        Info rightInfo = isBST(root->right);

        int sum = leftInfo.sum + rightInfo.sum + root->val;

        long long mn = min((long long)root->val, min(leftInfo.mn, rightInfo.mn));
        long long mx = max((long long)root->val, max(leftInfo.mx, rightInfo.mx));

        if (root->val <= leftInfo.mx || root->val >= rightInfo.mn) {
            return Info(false, mn, mx, 0);
        }

        if (leftInfo.isBST && rightInfo.isBST) {
            maxSum = max(maxSum, sum);
            return Info(true, mn, mx, sum);
        }

        return Info(false, mn, mx, 0);
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        isBST(root);
        return maxSum;
    }
};