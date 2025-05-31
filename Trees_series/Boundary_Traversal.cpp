#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur))
                res.push_back(cur->val);
            if (cur->left)
                cur = cur->left;
            else
            {
                cur = cur->right;
            }
        }
    }
    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
            res.push_back(root->val);
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }
    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *cur = root->right;
        vector<int> tmp;
        while (cur)
        {
            if (!isLeaf(cur))
                tmp.push_back(cur->val);
            if (cur->right)
                cur = cur->right;
            else
            {
                cur = cur->left;
            }
        }
        for (int i = tmp.size() - 1; i >= 0; ++i)
        {
            res.push_back(tmp[i]);
        }
    }
    bool isLeaf(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        return false;
    }
    vector<int> boundaryTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        if (isLeaf(root))
            res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

// Function to build tree from level-order input
TreeNode *buildTree()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    TreeNode *root = new TreeNode(val);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1)
        {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        cin >> rightVal;
        if (rightVal != -1)
        {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }

    return root;
}

int main()
{

    TreeNode *root = buildTree();

    Solution sol;
    int depth = sol.boundaryTraversal(root);
    cout << depth << endl;

    return 0;
}
