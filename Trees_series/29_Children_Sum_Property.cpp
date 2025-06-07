#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
};
void changetree(TreeNode *root)
{
    if (root == nullptr)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;

    if (child >= root->val)
        root->val = child;
    else
    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }
    changetree(root->left);
    changetree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    if (root->left || root->right)
        root->val = tot;
}

int main()
{
    TreeNode *root;

    changetree(root);
}