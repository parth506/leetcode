bool getPath(TreeNode *root, vector<int> &res, int x)
{
    if (root == nullptr)
        return false;

    res.push_back(root->val);

    if (root->val == x)
    {
        return true;
    }

    if (getPath(root->left, res, x) || getPath(root->right, res, x))
        return true;

    res.pop_back();
    return false;
}

vectior<int> solve(TreenOde *root, int x)
{
    vector<int> res;
    if (root == nullptr)
    {
        return res;
    }
    getPath(root, res, x);
    return res;
}