#include <bits/stdc++.h>
using namespace std;
struct knapsack
{
    double weight, benefit;
    int id;
};

bool compare(knapsack a, knapsack b)
{
    if (a.benefit > b.benefit)
    {
        return 1;
    }
    else
        return 0;
}

float find_benefit(int n, float weight, struct knapsack arr[])
{
    sort(arr, arr + n, compare);
    float current = 0.0;
    float ben = 0, remain = weight;
    for (int i = 0; i < n; i++)
    {
        if (current <= weight)
        {
            if (remain - arr[i].weight >= 1)
            {
                current += arr[i].weight;
                ben += (arr[i].weight * arr[i].benefit);
                remain -= arr[i].weight;
                // cout <<"c"<< current << " b" << ben << " r" << remain << endl;
            }
            else
            {
                current += arr[i].weight;
                ben += (remain * arr[i].benefit);
                remain -= arr[i].weight;
            }
        }
        else
            break;
    }
    return ben;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        float weight;
        cin >> weight;
        struct knapsack arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i].id = i;
            cin >> arr[i].benefit;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].weight;
        }
        float benefit = find_benefit(n, weight, arr);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i].benefit << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i].weight << " ";
        // }
        cout << endl
             << benefit << endl;
    }
}