#include <bits/stdc++.h>
using namespace std;
int memory[50][1000];
struct knapsack
{
    int ben, weight;
};

int zo_knapsack(struct knapsack arr[], int n, int w)
{
    if (w < 0)
    {
        return INT_MIN;
    }

    if (w == 0 || n < 0)
    {
        return 0;
    }
    if (memory[n][w] != -1)
    {
        return memory[n][w];
    }
    int res1 = zo_knapsack(arr, n - 1, w - arr[n].weight);
    int res2 = zo_knapsack(arr, n - 1, w);
    int res =  max(arr[n].ben + res1, res2);
    memory[n][w] = res;
    return res;
}

int main()
{
    // while (1)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                memory[i][j] = -1;
            }
        }

        int n, w;
        cin >> n >> w;
        struct knapsack arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].ben;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].weight;
        }
        cout << zo_knapsack(arr, n - 1, w) << endl;
    }
}