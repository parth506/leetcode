#include <bits/stdc++.h>

using namespace std;

TreeNode *{
    TreeNode * next,
    int val};
bool function(TreeNode *A, vector<int> &res, int B)
{
    if (A == nullptr)
        return false;
    res.push_back(A->val);
    if (A->val == B)
        return true;
    if (funtion(A->left, res, B) || function(A->right, res, B))
    {
        return true;
    }
    res.pop_back();

    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> res;
    function(A, res, B);
    return res;
}
int main()
{
}