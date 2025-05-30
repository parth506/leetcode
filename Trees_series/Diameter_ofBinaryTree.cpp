

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
    int maxi = 0;
    int check(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = check(root->left);
        int r = check(root->right);
        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {

        check(root);
        return maxi;
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
    int depth = sol.diameterOfBinaryTree(root);
    cout << depth << endl;

    return 0;
}
