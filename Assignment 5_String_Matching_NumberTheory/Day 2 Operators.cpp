#include <bits/stdc++.h>
using namespace std;
int main()
{
    double cost;
    cin >> cost;
    int tip, tax;
    cin >> tip >> tax;
    cost = cost + (cost / 100) * tip;
    cost = cost + (cost / 100) * tax;
    cout << cost << " " << (int)cost;
    return 0;
    if (cost - (int)cost >= 0.5)
    {
        cout << (int)cost + 1 << endl;
    }
    else
    {
        cout << (int)cost << endl;
    }
}