class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        vector<int> l(26, 0);
        vector<int> u(26, 0);

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                l[s[i] - 'a']++;
                s[i] = '#';
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                u[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        string ans = "";
        for (int i = 0; i < 26; ++i)
        {
            char c = 'A' + i;
            while (u[i])
            {
                ans += c;
                --u[i];
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            char c = 'a' + i;
            while (l[i])
            {
                ans += c;
                --l[i];
            }
        }
        int j = 0;
        int ind = 0;
        while (s[ind] != '\0' || ans[j] != '\0')
        {
            if (s[ind] == '#')
            {
                s[ind] = ans[j++];
            }
            ++ind;
        }
        return s;
    }
};