#include <bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        queue<TreeNode *> q;
        parent(root, parent_track, target);
        q.push(target);
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;
        int count = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (count++ == k)
            {
                break;
            }
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent_track[node] && !visited[parent_track[node]])
                {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }

        return res;
    }
};