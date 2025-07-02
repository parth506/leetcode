
// User function template for C++

class Solution
{
public:
    int longestPrefixSuffix(string &s)
    {
        // Your code goes here
        vector<int> lps(s.size(), 0);
        int pre = 0;
        int suf = 1;
        while (suf < s.size())
        {
            if (s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                ++suf;
                ++pre;
            }
            else
            {
                if (pre == 0)
                {
                    lps[suf] = 0;
                    ++suf;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[s.size() - 1];
    }
};