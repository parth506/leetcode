#include <bits/stdc++.h>
using namespace std;

int num(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else if (c == 'M')
        return 1000;
    else
        return 0;
}
int main()
{
    int sum = 0;
    string s;
    cin >> s;
    int ind = 0;
    while (ind < s.size() - 1)
    {
        if (num(s[ind]) < num(s[ind + 1]))
        {
            sum -= num(s[ind]);
        }
        else
        {
            sum += num(s[ind]);
        }
        ++ind;
    }
    sum += num(s[ind]);

    cout << sum << endl;
}