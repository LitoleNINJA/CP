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
    bool isValidBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL)
        {
            if (root->right->val > root->val)
                return isValidBST(root->right);
            else
                return false;
        }
        if (root->right == NULL)
        {
            if (root->left->val < root->val)
                return isValidBST(root->left);
            else
                return false;
        }
        if ((root->left->val < root->val) && (root->right->val > root->val))
            return isValidBST(root->left) && isValidBST(root->right);
        else
            return false;
    }
};