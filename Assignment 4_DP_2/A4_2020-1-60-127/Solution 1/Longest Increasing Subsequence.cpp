#include <bits/stdc++.h>
using namespace std;
int bin_search(int arr[], int key, int n)
{
    int high = n - 1;
    int low = 0;
    int res = -1;
    while (high >= low)
    {
       int  mid = (high + low) / 2;
        if (arr[mid] < key)
        {
            low = mid + 1;
            res = mid;
        }
        else if (arr[mid] == key)
        {
            return n - 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}

int lis(int arr[], int n)
{
    int arr2[n];
    arr2[0] = arr[0];
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr2[0] > arr[i])
        {
            arr2[0] = arr[i];
        }
        else if (arr2[count - 1] < arr[i])
        {
            arr2[count] = arr[i];
            count++;
        }
        else
        {
            arr2[bin_search(arr2, arr[i], count) + 1] = arr[i];
        }
    }
    return count;
}
int main()
{
    // while (1)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << lis(arr, n - 1) << endl;
    }
}