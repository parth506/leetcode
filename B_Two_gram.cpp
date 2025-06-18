#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> v;
    for (int i = 0; i < n - 1; ++i)
    {
        string d = string(1, s[i]) + string(1, s[i + 1]);
        v[d]++;
    }
    int res = INT_MIN;
    string ans;
    for (auto i : v)
    {
        if (res < i.second)
        {
            res = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;

    return 0;
}
