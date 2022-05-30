#include <stdio.h>
struct student
{
    float height;
    int roll;
};
void swap(struct student *x, struct student *y)
{
    struct student temp = *x;
    *x = *y;
    *y = temp;
}
int partition(struct student arr[], int first, int last)
{
    float pivot = arr[last].height;
    int i = first - 1;
    int j;
    for (j = first; j <= last - 1; j++) // till last-1 because last element is the pivot
    {
        if (arr[j].height <= pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j], &arr[i + 1]);
    return i + 1;
}

void quick_sort(struct student arr[], int first, int last)
{
    if (first < last)
    {
        int q = partition(arr, first, last);
        quick_sort(arr, first, q - 1);
        quick_sort(arr, q + 1, last);
    }
}
int main()
{
    int size;
    scanf("%d", &size);
    struct student arr[size];
    int flag = 1;
    for (int i = 1; i <= size; i++)
    {
        scanf("%f", &arr[i].height);
        arr[i].roll = i;
        if (i > 1 && arr[i - 1].height > arr[i].height)
        {
            flag = 0;
        }
    }

    int k;
    scanf("%d", &k);
    if (flag == 0) // if the flag == 1, then the array is alread sorted, which is the worst case of quick_sort
    {
        quick_sort(arr, 1, size);
    }
    printf("%d %.1f\n", arr[k].roll, arr[k].height);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%.1f ", arr[i].height);
    // }
}