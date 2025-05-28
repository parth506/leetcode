#include <bits/stdc++.h>
using namespace std;

void func(int i, vector<int> &ds, vector<int> &arr, int n)
{
    if (i == n)
    {
        for (auto i : ds)
        {
            cout << i << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[i]);
    func(i + 1, ds, arr, n);
    ds.pop_back();
    func(i + 1, ds, arr, n);
}
int main()
{
    int n;
    cin >> n;
    vector<int> ds;
    vector<int> arr = {3, 1, 2};
    func(0, ds, arr, n);
}
