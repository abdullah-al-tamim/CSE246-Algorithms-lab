#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
int status[40000];
vector<int> v;
void sieve()
{
    for (int i = 3; i <= sqrt(sqrt(MAX)); i++)
    {
        if (status[i] == 1)
        {
            for (int j = i * i; j <= sqrt(MAX); j += (2 * i))
            {
                status[j] = 0;
            }
        }
    }
    v.push_back(2);
    for (int i = 3; i <= sqrt(MAX); i += 2)
    {
        if (status[i] == 1)
        {
            v.push_back(i);
        }
    }
}

int main()
{
    for (int i = 0; i < sqrt(MAX); i++)
    {
        if (i > 2 && i % 2 == 0)
        {
            status[i] = 0;
        }
        else
            status[i] = 1;
    }
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = 1;
        for (int i = 0; i < v.size(); i++)
        {
            // cout << v.size();
            if (v[i] > n)
            {
                break;
            }
            else
            {
                if (n % v[i] == 0 && n != v[i])
                {
                    cout << "NOT PRIME" << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "PRIME" << endl;
        }
    }

    // for (int i = 2; i <= n; i++)
    // {
    //     if (status[i] == 1)
    //     {
    //         cout << i << " ";
    //     }
    // }
}