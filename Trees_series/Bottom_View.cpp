vector<int> topview(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q;
    map<int, int> m;

    q.push({root, 0});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int x = node.second;

        m[x] = node.first->val;
        if (node.first->left)
        {
            q.push(node.first->left, x - 1);
        }
        if (node.first->right)
        {
            q.push(node.first->right, x + 1);
        }
    }

    vector<int> ans;
    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}