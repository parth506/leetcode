class Solution
{
public:
    string longestSubsequenceRepeatedK(string s, int K)
    {
        int n = s.size();

        // Step 1: Preprocessing - Build nextPos table
        vector<vector<int>> nextPos(n + 2, vector<int>(26, n));

        // Step 1.1: Initialize end rows to sentinel n
        for (int c = 0; c < 26; ++c)
        {
            nextPos[n][c] = nextPos[n + 1][c] = n;
        }

        // Step 1.2: Fill table from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            for (int c = 0; c < 26; ++c)
            {
                nextPos[i][c] = nextPos[i + 1][c];
            }
            nextPos[i][s[i] - 'a'] = i;
        }

        // Step 2: Binary Search on length of repeated subsequence
        int low = 1;
        int high = n / K;
        string res = "";

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Step 2.1: Try to find valid subsequence of length mid using DFS
            string candidate = dfsTry(mid, K, 0, string(mid, ' '), s, nextPos);
            if (!candidate.empty())
            {
                res = candidate;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }

    // Step 3: DFS - Backtrack to build lexicographically largest valid subsequence
    string dfsTry(int len, int K, int idx, string path, const string &s, const vector<vector<int>> &nextPos)
    {
        if (idx == len)
        {
            return canExtend(path, len, s, nextPos, K) ? path : "";
        }

        for (int c = 25; c >= 0; --c)
        {
            path[idx] = 'a' + c;

            if (canExtend(path, idx + 1, s, nextPos, K))
            {
                string sub = dfsTry(len, K, idx + 1, path, s, nextPos);
                if (!sub.empty())
                {
                    return sub;
                }
            }
        }

        return "";
    }

    // Step 4: Check if (prefix of length d) * K is a subsequence of s
    bool canExtend(const string &path, int d, const string &s, const vector<vector<int>> &nextPos, int K)
    {
        int pos = 0;
        int n = s.size();

        for (int rep = 0; rep < K; ++rep)
        {
            for (int i = 0; i < d; ++i)
            {
                int c = path[i] - 'a';
                if (pos >= n)
                {
                    return false;
                }

                pos = nextPos[pos][c];
                if (pos == n)
                {
                    return false;
                }

                ++pos;
            }
        }

        return true;
    }
};