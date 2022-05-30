#include <stdio.h>

int upperBound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        if (arr[mid] > key && arr[mid - 1] <= key && arr[mid] != arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > key && arr[mid - 1] <= key && arr[mid] == arr[mid + 1])
        {
            while (arr[mid] == arr[mid + 1])
            {
                mid++;
            }
            return mid;
        }
        else if (arr[mid] <= key)
        {
            // printf("H");
            upperBound(arr, mid, high, key);
        }
        else
        {
            upperBound(arr, low, mid, key);
        }
    }
}

int lowerBound(int arr[], int low, int high, int key)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2) ;
        if (arr[mid] <= key && arr[mid + 1] > key && arr[mid] != arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] <= key && arr[mid + 1] > key && arr[mid] == arr[mid - 1])
        {
            while (arr[mid] == arr[mid - 1])
            {
                if (mid - 1 == 0)
                {
                    return 0;
                }

                mid--;
            }
            return mid;
        }
        else if (arr[mid] < key)
        {
            lowerBound(arr, mid + 1, high, key);
        }
        else
        {
            lowerBound(arr, low, mid, key);
        }
    }
}

int main()
{
    // while (1)
    {
        int n;
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

        printf("\nUpper bound: %d", upperBound(arr, 0, n, s));
    }
}
