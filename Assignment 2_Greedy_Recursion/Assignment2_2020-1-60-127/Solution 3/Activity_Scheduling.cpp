#include <bits/stdc++.h>
using namespace std;

struct tasks
{
    int start, end;
};

bool compare(tasks a, tasks b)
{
    if (a.end < b.end)
    {
        return 1;
    }
    else
        return 0;
}

int compare_schedule(struct tasks arr[], int n)
{
    int count = 1, j;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i].end <= arr[i + 1].start)
        {
            // cout << "checked:" << arr[i].start << " " << arr[i].end << endl;

            count++;
        }
        else
        {
            j = i + 1;
            while (arr[i].end > arr[j].start && j < n)
            {
                j++;
            }
            if (arr[i].end < arr[j].start)
            {
                count++;
                i = j-1;
            }
        }
    }
    return count;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        tasks arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].start >> arr[i].end;
        }
        sort(arr, arr + n, compare);
        int res = compare_schedule(arr, n);
        cout << res << endl;
    }
}