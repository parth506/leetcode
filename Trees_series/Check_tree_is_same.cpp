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
    int check(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr || root2 == nullptr)
        {
            return (root1 == root2);
        }

        return (root1->val == root2->val) &&
               check(root1->left, root2->left) &&
               check(root1->right, root2->right);
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
    int depth = sol.check(root, root);
    cout << depth << endl;

    return 0;
}
