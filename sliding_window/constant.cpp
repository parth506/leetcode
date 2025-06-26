#include <bits/stdc++.h>
using namespace std;
// maximum sum with constant window
int constant_window(vector<int> &s, int k)
{
    int l = 0;
    int r = k - 1;
    int sum = 0;

    for (int i = l; i <= r; ++i)
    {
        sum += s[i];
    }
    int ans = sum;
    while (r < s.size() - 1)
    {
        sum = sum - s[l];

        ++l;
        ++r; // this is where we understand the logic of [ s.size()-1 ] in while loop
        sum = sum + s[r];

        ans = max(ans, sum);
    }
    return ans;
}
int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> str(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];
    }
    int ans;
    ans = constant_window(str, k);
    cout << ans << endl;
}