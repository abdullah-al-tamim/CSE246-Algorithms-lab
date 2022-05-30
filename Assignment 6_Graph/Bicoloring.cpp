#include <bits/stdc++.h>
using namespace std;
#define inf 100000000
char color[1000];
int dis[1000];
bool bicolor(vector<int> graph[], int u, int v, int e)
{
    int bi[1000];
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        color[i] = 'w';
        dis[i] = inf;
        bi[i] = 0;
    }
    color[u] = 'g';
    dis[u] = 0;
    bi[u] = 1;
    q.push(u);
    while (!q.empty())
    {
        int curr = q.front();
        cout << "Q: " << curr << endl;
        q.pop();
        for (int i = 0; i < (int)graph[curr].size(); i++)
        {
            // cout << "graph[curr][i]: " << graph[curr][i] << endl;
            // cout << "Color: " << color[graph[curr][i]] << endl;

            if (bi[graph[curr][i]] == 0)
            {
                if (bi[curr] == 1)
                {
                    bi[graph[curr][i]] = 2;
                }
                else if (bi[curr] == 2)
                {
                    bi[graph[curr][i]] = 1;
                }
            }
            cout << "Bi: "<<bi[graph[curr][i]] << endl;
            if (bi[curr] != 0 && bi[curr] == bi[graph[curr][i]])
            {
                return false;
            }

            if (color[graph[curr][i]] == 'w')
            {
                color[graph[curr][i]] = 'g';
                dis[graph[curr][i]] = dis[curr] + 1;
                q.push(graph[curr][i]);
            }
        }
        color[curr] = 'b';
    }
    return true;
}
int main()
{
    // while (1)
    {
        // #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // #endif
        int v, e;
        cin >> v >> e;
        vector<int> graph[v + 1];
        int x, y;
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for (int i = 0; i < v; i++)
        {
        }
        if (bicolor(graph, 1, v, e))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}