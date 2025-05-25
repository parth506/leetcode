#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{

    int prev = 1;
    int prev2 = 1;
    for (int i = 2; i <= n; ++i)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    int c = climbStairs(n);
    cout << c;
}