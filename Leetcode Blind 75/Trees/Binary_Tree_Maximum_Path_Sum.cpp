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
    int mx = INT_MIN;
    int maxTree(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int l = max(maxTree(node->left), 0);
        int r = max(maxTree(node->right), 0);
        mx = max(mx, node->val + l + r);
        return (node->val + max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        maxTree(root);
        return mx;
    }
};