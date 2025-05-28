#include <bits/stdc++.h>
using namespace std;

int func(int i, vector<int> &ds, vector<int> &a, int sum, int k, int c)
{
    if (i == a.size())
    {
        if (sum == k)
        {
            // print ds
            // for (auto it : ds)
            // {
            //     cout << it << " ";
            // }
            // cout << endl;
            ++c;
        }
        return c;
    }
    // take
    ds.push_back(a[i]);
    sum += a[i];
    c = func(i + 1, ds, a, sum, k, c);

    // non_take
    ds.pop_back();
    sum -= a[i];
    c = func(i + 1, ds, a, sum, k, c);
    return c;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a = {1, 2, 1};
    vector<int> ds;
    int c = 0;
    int count = func(0, ds, a, 0, k, c);
    cout << count << endl;
}
