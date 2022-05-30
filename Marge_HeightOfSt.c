#include <stdio.h>
struct node
{
    int roll;
    float height;
};
void marge(struct node array[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;
    struct node L[n1], M[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = array[q + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i].height <= M[j].height)
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }
    // printf("%f\n",array[k-1].height);
    // printf("%d  %d \n ",i,j);
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }
}
void margeSort(struct node array[], int l, int r)
{
    if (l < r)
    {
        // printf("%f\n",array[1].height);
        int m = (l + (r - 1)) / 2;
        margeSort(array, l, m);
        margeSort(array, m + 1, r);
        marge(array, l, m, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node array[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%f", &array[i].height);
        array[i].roll = i;
    }
    int k;
    scanf("%d", &k);
    margeSort(array, 1, n);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", array[i].roll);
    // }
    // printf("%d\n", array[k].roll);
    printf("\n%d\n",array[k].roll);

    for (int i = 1; i <= n; i++)
    {
        printf("%0.2f ", array[i].height);
    }
}
