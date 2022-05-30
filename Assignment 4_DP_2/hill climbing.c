#include <stdio.h>
// using namespace std;
int m, n;
int hill_climb(int *arr, int i, int j)
{
    if (i < 0 || i > m)
    {
        return 0;
    }
    if (j < 0 || j > n)
    {
        return INT_MAX;
    }
    return min(*((arr + i * n) + j) + hill_climb(arr, i - 1, j), *((arr + i * n) + j) + hill_climb(arr, i - 1, j - 1), *((arr + i * n) + j) + hill_climb(arr, i - 1, j + 1));
}

int main()
{
    // int m, n;
    scanf
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << hill_climb((int *)arr, m, n);
}