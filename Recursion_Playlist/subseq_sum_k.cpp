#include <bits/stdc++.h>
using namespace std;

void func(int i, vector<int> &ds, vector<int> &a, int sum, int k)
{
    if (i == a.size())
    {
        if (sum == k)
        {
            // print ds
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    // take
    ds.push_back(a[i]);
    sum += a[i];
    func(i + 1, ds, a, sum, k);

    // non_take
    ds.pop_back();
    sum -= a[i];
    func(i + 1, ds, a, sum, k);
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a = {1, 2, 1};
    vector<int> ds;
    func(0, ds, a, 0, k);
}
