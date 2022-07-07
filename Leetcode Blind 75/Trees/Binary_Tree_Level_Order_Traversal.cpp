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
    int height(TreeNode* node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int lDepth = height(node->left);
            int rDepth = height(node->right);
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        int n = height(root);
        vector<vector<int>> ans(n + 1);
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            TreeNode *node = p.first;
            ans[p.second].push_back(node->val);
            if (node->left != NULL)
                q.push({node->left, p.second + 1});
            if (node->right != NULL)
                q.push({node->right, p.second + 1});
        }
        return ans;
    }
};