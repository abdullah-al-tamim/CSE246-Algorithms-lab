#include <bits/stdc++.h>
using namespace std;
int memory[1000][1000];
int arr[1000];
vector<int> v;
int min_coins(int i, int k)
{
    // if (k<0)
    // {
    //     return INT_MIN;
    // }

    if (i < 0 || k == 0)
    {
        return 0;
    }
    int res1, res = INT_MAX;
    int j = 0;
    if (memory[i][k] != -1)
    {
        return memory[i][k];
    }
    // v.push_back(arr[0]);
    while (j <= i)
    {
        if (arr[j] <= k)
        {
            res1 = 1 + min_coins(i, k - arr[j]);

            // res = min(res, res1);
            if (res1 < res)
            {
                // v.pop_back();
                // v.push_back(arr[i]);
                res = res1;
            }

            // res2 = min_coins(arr, i - 1, k);
        }
        j++;
    }
    memory[i][k] = res;
    return res;
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
        }

        int n, k;
        cin >> n >> k;
        // int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << min_coins(n - 1, k) << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
}