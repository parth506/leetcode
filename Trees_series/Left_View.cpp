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
class Solution
{
public:
    void preoreder(TreeNode *root, int level, vector<int> &res)
    {
        if (root == nullptr)
            return;
        if (level == res.size())
        {
            res.push_back(root->val);
        }

        preoreder(root->left, level + 1, res);
        preoreder(root->right, level + 1, res);
    }
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> res;
        preoreder(root, 0, res);
        return res;
    }
};