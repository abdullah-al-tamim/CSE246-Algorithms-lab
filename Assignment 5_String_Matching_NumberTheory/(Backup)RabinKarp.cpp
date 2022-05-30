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

// int rehash(char txt[], int i, int end, int t, int m)
// {
//     int newhash = t - txt[i];
//     newhash = (newhash / 2);
//     newhash += txt[end] + pow(2, m - 1);
// }

void rabinkarp(char txt[], char pat[])
{
    int m = strlen(pat);
    int n = strlen(txt);
    int p = 0, offset = 1;
    int t[n];
    t[0] = 0;
    p = hashfunction(pat, 0, m);
    // t = hashfunction(txt, 0, m);
    for (int i = 0; i < m; i++)
    {
        offset = (2 * offset) % prime;
    }
    // for (int i = 0; i < m; i++)
    // {
    //     t[0] = (2 * t[0] + txt[i]) % prime;
    // }

    // cout << offset << endl;
    // return ;
    for (int i = 0; i <= n - m; i++)
    {
        // t[i] = (2 * (t[i - 1] - offset * txt[i - 1]) + txt[i + m - 1]) % prime;
        t[i] = 0;
        for (int j = 0; j < m; j++)
        {
            t[i] = (2 * t[i] + txt[i + j]) % prime;
        }

        cout << t[i] << endl;
    }

    for (int i = 0; i <= n - m; i++)
    {

        // cout << i << endl;
        // for (int j = i; j < i + m; j++)
        // {
        //     cout << txt[j];
        // }
        // cout << " ";
        // for (int j = 0; j < m; j++)
        // {
        //     cout << pat[j];
        // }
        // cout << endl;

        // cout << p << " ";
        // cout << i << endl;
        if (p == t[i])
        {
            int j;
            for (j = 0; j < m; j++)
            {
                // cout << txt[i + j-1] << " " << pat[j] << endl;
                // cout << i << endl;
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            // cout << j  << " " << m << endl;
            if (j == m)
            {
                cout << i << " " << i + m - 1 << endl;
            }
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