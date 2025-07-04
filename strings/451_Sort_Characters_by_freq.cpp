class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m;
        multimap<int, char> r;
        string t = "";
        for (int i = 0; i < s.size(); ++i)
        {
            m[s[i]]++;
        }
        for (auto a : m)
        {
            r.insert({a.second, a.first});
        }
        for (auto i = r.rbegin(); i != r.rend(); ++i)
        {
            t = t + string(i->first, i->second);
        }

        return t;
    }
};