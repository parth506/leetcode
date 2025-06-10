class Solution
{
public:
    string defangIPaddr(string address)
    {
        string s;
        for (int i = 0; i < address.size(); ++i)
        {
            if (address[i] == '.')
            {
                s = s + "[.]";
            }
            else
            {
                s = s + address[i];
            }
        }
        return s;
    }
    //     string defangIPaddr(string address) {
    //   return regex_replace(address, regex("[.]"), "[.]");
    // }
};