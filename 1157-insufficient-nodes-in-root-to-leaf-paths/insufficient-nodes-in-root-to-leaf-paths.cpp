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
    TreeNode* dfs(TreeNode* root, int sum, int limit) {
        if (root == NULL)
            return NULL;

        sum += root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum < limit)
                return NULL;

            return root;
        }

        root->left = dfs(root->left, sum, limit);
        root->right = dfs(root->right, sum, limit);

        // If both children were deleted
        if (root->left == NULL && root->right == NULL)
            return NULL;

        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }
};