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
    int n;
    cin >> n;
    string s = "";

    cout << s << endl;
}