#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    vector<int> vv;
    int i = 0;
    int x;
    cin >> x;
    while (x != 1000)
    {
        v.push_back(x);
        cin >> x;
        i++;
    }
    i = 0;
    cin >> x;
    while (x != 1000)
    {
        vv.push_back(x);
        cin >> x;
        i++;
    }
    if (v.size() == vv.size())
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != vv[i])
            {
                cout << "Doesn't match" << endl;
            }
        }
        if (i == v.size())
        {
            cout << "Perfect" << endl;
        }
    }
    else
        cout << "Doesn't match" << endl;
}