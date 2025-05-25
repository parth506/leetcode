class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        for (int k = 0; k < m; ++k)
        {
            if (s[i] == t[j])
            {
                ++i;
                ++j;
            }
            else
            {
                ++j;
            }
        }
        if (i >= n)
            return true;
        return false;
    }
};