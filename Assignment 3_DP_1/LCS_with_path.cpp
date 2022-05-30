#include <bits/stdc++.h>
using namespace std;
int memory[40][40];
char x[40], y[40];
vector<char> v;
int lcs(int i, int j)
{
    if (i >= strlen(x) || j >= strlen(y))
    {
        return 0;
    }
    if (memory[i][j] != -1)
    {
        return memory[i][j];
    }

    int res1 = 0, res2 = 0, res3 = 0;
    if (x[i] == y[j])
    {
        res1 = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        res2 = lcs(i + 1, j);
        res3 = lcs(i, j + 1);
        // if (res2 > res3)
        // {
        //     v.push_back(x[i + 1]);
        //     v.push_back(y[j]);
        // }
        // else
        // {
        //     v.push_back(x[i]);
        //     v.push_back(y[j + 1]);
        // }  
        res2 = max(res2, res3);
    }
    // if (res1>res2||res1>res3)
    // {
    //     v.pop_back();
    //     v.pop_back();
    //     v.push_back(x[i + 1]);
    //     v.push_back(y[j + 1]);
    // }
    
    memory[i][j] = max(res1, res2);
    // cout << res1 << res2 << res3 << endl;
    return max(res1, res2);
}
int main()
{
    while (1)
    {
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                memory[i][j] = -1;
            }
        }

        cin >> x >> y;
        // cout << x << " " << y << endl;
        cout << lcs(0, 0) << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        
    }
}