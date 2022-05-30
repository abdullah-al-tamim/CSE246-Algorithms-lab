#include <bits/stdc++.h>
using namespace std;
#define inf 1e8
int v, e;
char color[3000];
int pre[3000];
int fin[3000];
int dis[3000];
int t = 0;
int dfs_visit(vector<int> graph[], int s, int count)
{
    cout <<"c"<< count<<" " ;
    color[s] = 'g';
    t++;
    dis[s] = t;
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (color[graph[s][i]] == 'w')
        {
            pre[graph[s][i]] = s;
            cout << "v" << graph[s][i]<<" ";
            count = max(count, dfs_visit(graph, graph[s][i], count+=1));
        }
    }
    color[s] = 'b';
    t++;
    fin[s] = t;
    return count;
}

void dfs(vector<int> graph[])
{
    for (int i = 1; i <= v; i++)
    {
        color[i] = 'w';
        pre[i] = -1;
        fin[i] = inf;
        dis[i] = inf;
    }
    int res = 1e-8;
    for (int i = 1; i <= v; i++)
    {
        if (color[i] == 'w')
        {
            res = max(dfs_visit(graph, i, 1), res);
        }
    }
    cout << "\n"
         << res << endl;
}
int main()
{
    cin >> v >> e;
    vector<int> graph[v + 1];
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(graph);
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << "vertex " << i;
    //     for (int j = 0; j < (int)graph[i].size(); j++)
    //     {
    //         cout << " --> " << graph[i][j];
    //     }
    //     // cout << graph[i].size() << endl;
    //     cout << endl;
    // }
    // for (int i = 1; i <= v; i++)
    // {
    //     if (color[i] == 'b')
    //     {
    //         cout << "visited: " << i << ", Dis: " << dis[i] << ", Fin: " << fin[i] << endl;
    //     }
    // }
}