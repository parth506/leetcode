#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> h;
        unordered_map<char, char> b;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == t[i] && !h[s[i]] && !b[t[i]])
            {
                h[s[i]] = t[i];
                s[i] = t[i];
                b[t[i]] = s[i];
            }
            else if (s[i] != t[i] && !h[s[i]] && !b[t[i]])
            {
                h[s[i]] = t[i];
                s[i] = t[i];
                b[t[i]] = s[i];
            }
            else
            {
                s[i] = h[s[i]];
            }
        }
        if (s == t)
            return true;
        else
            return false;
    }
};