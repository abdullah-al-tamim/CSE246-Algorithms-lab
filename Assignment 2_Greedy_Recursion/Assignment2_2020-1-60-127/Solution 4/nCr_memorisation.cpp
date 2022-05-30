#include <bits/stdc++.h>
using namespace std;
long long memory[1000][1000];

long long fact(long long n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

long long ncr(long long n, long long r)
{
    if (r == 0 && r >= n)
    {
        return 1;
    }
    if (memory[n][r] != -1)
    {
        return memory[n][r];
    }

    long long res = fact(n) / (fact(r) * fact(n - r));
    memory[n][r] = res;
    return res;
}

int main()
{
    while (1)
    {
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                memory[i][j] = -1;
            }
        }

        long long n, r;
        cin >> n >> r;
        if (n>=r)
        {
            
        cout << ncr(n, r) << endl;
        }
        
    }
}