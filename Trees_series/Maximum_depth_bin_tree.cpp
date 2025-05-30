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
// class Solution
// {

// public:
//     int maxDepth(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int l = maxDepth(root->left);
//         int r = maxDepth(root->right);

//         return 1 + max(l, r);
//     }
// };
class Solution
{

public:
    int maxDepth(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        if (root == nullptr)
            return ans.size();
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0;)
        }
    }
};

int main()
{
    // Constructing a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << depth << endl;

    return 0;
}
