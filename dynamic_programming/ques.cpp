#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> orbs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> orbs[i];
    }

    int cycles = 0;
    int current = 0;

    while (current < n)
    {
        // Find the longest palindrome starting at current position
        int longest_end = current;
        for (int end = n - 1; end >= current; --end)
        {
            bool is_palindrome = true;
            for (int i = current, j = end; i < j; ++i, --j)
            {
                if (orbs[i] != orbs[j])
                {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome)
            {
                longest_end = end;
                break;
            }
        }
        ++cycles;
        current = longest_end + 1;
    }

    cout << cycles << '\n';
    return 0;
}