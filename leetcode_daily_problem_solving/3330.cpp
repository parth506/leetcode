#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int possibleStringCount(string word)
    {
        unordered_map<int, int> m;
        int sum = 0;
        for (int i = 0; i < word.size() - 1; ++i)
        {

            if (word[i] == word[i + 1])
                m[word[i] - 'a']++;
        }
        for (auto i : m)
        {

            sum = sum + i.second;
        }
        return sum + 1;
    }
};