#include <bits/stdc++.h>
using namespace std;
#define prime 101
int hashfunction(char str[], int i, int n)
{
    int hash = 0;
    for (; i < n; i++)
    {
        hash = (2 * hash + str[i]) % prime;
    }
    return hash;
}

void rabinkarp(char txt[], char pat[])
{
    int m = strlen(pat);
    int n = strlen(txt);
    int p = 0;
    int t = 0;
    int offset = 1;

    for (int i = 0; i < m - 1; i++)
        offset = (offset * 2) % prime;

    p = hashfunction(pat, 0, m);
    t = hashfunction(txt, 0, m);

    for (int i = 0; i <= n - m; i++)
    {

        if (p == t)
        {
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }

            if (j == m)
                cout << i << " " << i + m - 1 << endl;
        }

        if (i < n - m)
        {
            t = (2 * (t - txt[i] * offset) + txt[i + m]) % prime;
            if (t < 0)
                t = (t + prime);
        }
    }
}

int main()
{
    char text[100005];
    cin >> text;
    char pattern[1001];
    cin >> pattern;
    // cout << text << endl;
    // cout << pattern<< endl;
    rabinkarp(text, pattern);
}