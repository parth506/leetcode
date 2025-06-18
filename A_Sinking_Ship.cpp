#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> rats;
    vector<string> women_children;
    vector<string> men;
    string captain;

    for (int i = 0; i < n; ++i)
    {
        string name, status;
        cin >> name >> status;

        if (status == "rat")
        {
            rats.push_back(name);
        }
        else if (status == "woman" || status == "child")
        {
            women_children.push_back(name);
        }
        else if (status == "man")
        {
            men.push_back(name);
        }
        else if (status == "captain")
        {
            captain = name;
        }
    }

    for (const string &name : rats)
        cout << name << '\n';
    for (const string &name : women_children)
        cout << name << '\n';
    for (const string &name : men)
        cout << name << '\n';
    cout << captain << '\n';

    return 0;
}
