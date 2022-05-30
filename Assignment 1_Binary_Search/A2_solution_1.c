#include <stdio.h>
int n;
int bin_lower_bound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        if (arr[mid] == key && arr[mid - 1] < key || (mid == 0 && arr[mid] == key))
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return bin_lower_bound(arr, mid, high, key);
        }

        else
        {
            return bin_lower_bound(arr, low, mid, key);
        }
    }
    else
    {
        while (arr[high] == arr[high - 1])
        {
            high--;
        }
        return high;
    }
}

int bin_upper_bound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        if ((arr[mid] == key && arr[mid + 1] > key) || (mid == n - 1 && arr[mid] == key))
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return bin_upper_bound(arr, low, mid, key);
        }
        else
        {
            return bin_upper_bound(arr, mid, high, key);
        }
    }
    else
    {
        while (arr[high] == arr[high + 1])
        {
            high++;
        }
        return high;
    }
}
int upperBound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        printf("\n%d, %d, %d", low, mid, high);
        if (mid > low)
        {
            if (arr[mid] > key && arr[mid - 1] <= key && arr[mid] != arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > key && arr[mid - 1] <= key && arr[mid] == arr[mid + 1])
            {
                return bin_upper_bound(arr, mid, n, arr[mid]);
            }
            else if (arr[mid] <= key)
            {

                return upperBound(arr, mid, high, key);
            }
            else
            {
                return upperBound(arr, low, mid, key);
            }
        }
        else
        {
            if (low == n - 1)
            {
                return n;
            }
            else
               {
                   return bin_upper_bound(arr, low, n, arr[mid]);
               }
        }
    }
    else
    {
        while (arr[low] == arr[low + 1])
        {
            low++;
        }
        return low;
    }
}

int lowerBound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        printf("\nlow: %d, %d, %d", low, mid, high);
        if (mid > low)
        {
            if (arr[mid] <= key && arr[mid + 1] > key && arr[mid] != arr[mid - 1])
            {
                return mid;
            }
            else if (arr[mid] <= key && arr[mid + 1] > key && arr[mid] == arr[mid - 1])
            {
                return bin_lower_bound(arr, low, mid, arr[mid]);
            }
            else if (arr[mid] <= key)
            {
                return lowerBound(arr, mid, high, key);
            }
            else
            {
                return lowerBound(arr, low, mid, key);
            }
        }
        else
            return low;
    }
    else
    {
        while (arr[high] == arr[high-1])
        {
            high++;
        }
        return high;
    }
}

int main()
{
    while (1)
    {

        int s;

        scanf("%d", &n);
        scanf("%d", &s);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        // if (s < arr[0])
        // {
        //     printf("\nLower bound: 0 ");
        //     printf("\nUpper bound: 0 ");
        //     return;
        // }
        // if (s > arr[n - 1])
        // {
        //     printf("\nLower bound: %d ", n - 1);
        //     printf("\nUpper bound: %d ", n);
        //     return;
        // }

        printf("\nLower bound: %d", lowerBound(arr, 0, n, s));

        printf("\nUpper bound: %d\n", upperBound(arr, 0, n, s));
    }
}
