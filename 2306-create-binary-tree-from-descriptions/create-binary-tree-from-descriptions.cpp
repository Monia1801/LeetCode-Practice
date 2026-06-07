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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;

        for (auto &d : descriptions) {
            int parent = d[0], c = d[1], isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);
            if (!mp.count(c))
                mp[c] = new TreeNode(c);

            if (isLeft)
                mp[parent]->left = mp[c];
            else
                mp[parent]->right = mp[c];

            child.insert(c);
        }

        for (auto &p : mp) {
            if (!child.count(p.first))
                return p.second;
        }

        return nullptr;
    }
};