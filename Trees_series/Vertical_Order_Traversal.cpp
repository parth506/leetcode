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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes; // map<v,level,nodes>
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto r = q.front();
            q.pop();
            int x = r.second.first, y = r.second.second;
            TreeNode *no = r.first;
            nodes[x][y].insert(no->val);
            if (no->left)
            {
                q.push({no->left, {x - 1, y + 1}});
            }
            if (no->right)
            {
                q.push({no->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto i : nodes)
        {
            vector<int> col;
            for (auto j : i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};