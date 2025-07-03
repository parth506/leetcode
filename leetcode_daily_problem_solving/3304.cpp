class Solution
{
public:
    char kthCharacter(int k)
    {
        string w = "a";
        while (w.size() < k)
        {
            string s = "";
            for (int i = 0; i < w.size(); ++i)
            {
                char c = w[i] + 1;
                s.push_back(c);
            }
            w.append(s);
        }

        return w[k - 1];
    }
};