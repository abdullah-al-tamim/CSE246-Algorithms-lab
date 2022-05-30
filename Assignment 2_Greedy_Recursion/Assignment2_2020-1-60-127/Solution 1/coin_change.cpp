#include <bits/stdc++.h>
using namespace std;
void count_coin(int amount, int arr[], int size)
{
    int count = 0;
    while (amount != 0 && size>=0)
    {
        for (int i = 1; i <= amount; i++)
        {
            // printf("%d  ", arr[size-1]);
            if ((amount / (arr[size] * i)) == 1)
            {
                //printf("\n%d of %d note is needed\n", i, arr[size]);
                count+=i;
                amount -= (arr[size] * i);
                break;
            }
            else if ((amount / (arr[size] * i)) < 1)
            {
                size--;
                break;
            }
        }
    }
    printf("\n%d", count);
}

int main()
{
    while (1)
    {
        int n;
        int amount;
        cin >> n;
        cin >> amount;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }

        count_coin(amount, arr, n - 1);
    }
}