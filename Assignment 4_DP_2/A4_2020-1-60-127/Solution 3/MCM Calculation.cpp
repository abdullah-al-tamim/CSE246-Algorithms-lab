#include <bits/stdc++.h>
using namespace std;
int memory[1000][1000];
struct matrix
{
    int row, col;
};

int mcm(int i, int k, struct matrix arr[])
{
    int res = INT_MAX, r;
    if (i == k)
    {
        return 0;
    }
    if (memory[i][k] != -1)
    {
        return memory[i][k];
    }

    for (int j = i; j < k; j++)
    {
        res = min(res, mcm(i, j, arr) + mcm(j + 1, k, arr) + (arr[i].row * arr[j].col * arr[k].col));
    }
    memory[i][k] = res;
    return res;
}

int main()
{
    // while (1)
    {
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                memory[i][j] = -1;
            }
        }

        int n;
        cin >> n;
        struct matrix arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].row >> arr[i].col;
        }
        int res = mcm(0, n - 1, arr);
        cout << res;
    }
}