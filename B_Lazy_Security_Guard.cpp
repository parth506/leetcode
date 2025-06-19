#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int min_perimeter = 4 * N; // Initial large value (worst case)

    for (int i = 1; i <= sqrt(N); ++i)
    {
        int j = (N + i - 1) / i; // Equivalent to ceil(N / i)
        int perimeter = 2 * (i + j);
        min_perimeter = min(min_perimeter, perimeter);
    }

    cout << min_perimeter << endl;
    return 0;
}
