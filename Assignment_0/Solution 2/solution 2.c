#include <stdio.h>
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    int j;
    for (j = p; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j], &arr[i + 1]);
    return i + 1;
}

void quick_sort(int arr[], int f, int l)
{
    if (f < l)
    {
        int q = partition(arr, f, l);
        quick_sort(arr, f, q - 1);
        quick_sort(arr, q + 1, l);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int min = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        // min = arr[i+1] - arr[i];
        // printf("%d ", min);
        // if (min<0)
        // {
        //     min*=-1;
        // }
        if ((arr[i + 1] - arr[i]) < min)
        {
            min = arr[i + 1] - arr[i];
        }
    }
    printf("\n%d", min);
}
