#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution

{

public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (l == -1 || r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return maxDepth(root) != -1;
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
    bool depth = sol.isBalanced(root);
    cout << depth << endl;

    return 0;
}
