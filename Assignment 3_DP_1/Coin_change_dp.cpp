#include <bits/stdc++.h>
using namespace std;
int memory[1000][1000];
struct data
{
    int coin, times;
};
// int j = 0;
struct data used[1000];
int min_coins(int arr[], int i, int k, int n)
{
    // if (k<0)
    // {
    //     return INT_MIN;
    // }

    if (i > n || k == 0)
    {
        return 0;
    }
    int res = INT_MAX;
    if (memory[i][k] != -1)
    {
        return memory[i][k];
    }
    if (arr[i] <= k)
    {
        int res1, res2;
        res1 = 1 + min_coins(arr, i, k - arr[i], n);
        res2 = min_coins(arr, i + 1, k, n);
        // if (res1 <= res2)
        // {
        //     if (used[j].coin != -1 && used[j].coin == arr[i])
        //     {
        //         used[j].times++;
        //     }
        //     else
        //     {
        //         used[j].coin = arr[i];
        //         used[j].times++;
        //     }
        // }
        // else if (res1 > res2)
        // {
        //     if (used[j].coin != -1 && used[j].coin == arr[i+1])
        //     {
        //         used[j].times++;
        //     }
        //     else
        //     {
        //         used[j].coin = arr[i + 1];
        //         used[j].times++;
        //     }
        // }
        // j++;
        res = min(res1, res2);
        memory[i][k] = res;
        return res;
    }
    // else
    // {
    //     min_coins(arr, i - 1, k);
    //     // return min(1 + res1, res2);
    // }
}

int main()
{
    while (1)
    {
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                memory[i][j] = -1;
            }
            used[i].coin = -1;
            used[i].times = 0;
        }

        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int res = min_coins(arr, 0, k, n);
        cout << res << endl;
        // for (int i = 0; i < 50; i++)
        // {
        //     cout << used[i].coin << " " << used[i].times << endl;
        // }
    }
}