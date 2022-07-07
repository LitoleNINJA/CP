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
    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans1 = level(root->left) + 1;
        int ans2 = level(root->right) + 1;
        return max(ans1, ans2);
    }
    int maxDepth(TreeNode* root) {
        return level(root);
    }
};