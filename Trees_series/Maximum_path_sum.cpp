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
    int maxi = INT_MIN;
    int maxPathSum(TreeNode *root, int maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = max(0, maxPathSum(root->left, maxi));
        int r = max(0, maxPathSum(root->right, maxi));
        maxi = max(maxi, l + r + root->val);
        return root->val + max(l, r);
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
    int depth = sol.maxPathSum(root, 0);
    cout << depth << endl;

    return 0;
}
