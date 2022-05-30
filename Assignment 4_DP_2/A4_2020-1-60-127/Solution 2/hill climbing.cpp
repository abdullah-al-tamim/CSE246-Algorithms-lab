#include <bits/stdc++.h>
using namespace std;
#define MAX_VAL 1000000000

int m, n;
int arr[1000][1000];
int memory[1000][1000];
int hill_climb(int i, int j)
{
    if (i < 0 && j == n)
    {
        return 0;
    }
    if (j < 0 || j >= n)
    {
        return MAX_VAL;
    }
    if (memory[i][j] != -1)
        return memory[i][j];
    int res = MAX_VAL;
    int res1 = arr[i][j] + hill_climb(i - 1, j);
    int res2 = arr[i][j] + hill_climb(i - 1, j - 1);
    res = min(res1, res2);
    int res3 = arr[i][j] + hill_climb(i - 1, j + 1);
    res = min(res, res3);
    memory[i][j] = res;
    // cout << res1 << " " << res2 << " " << res3 << endl;
    return res;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(memory, -1, sizeof(memory));
    int res = MAX_VAL;
    for (int i = 0; i < n; i++)
    {
        res = min(hill_climb(m - 1, i), res);
    }
    cout << res << endl;
    //}
    return 0; // ending memoryment
}
