#include <bits/stdc++.h>
using namespace std;
#define inf 1e8
int v, e;
int pre[3000];
int dis[3000];
char color[3000];
int lim = 2;
int bfs(vector<int> graph[], int s)
{
    for (int i = 1; i <= v; i++)
    {
        color[i] = 'w';
        dis[i] = inf;
        pre[i] = -1;
    }
    color[s] = 'g';
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    int index = -1, max_dis = 1e-8;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        // cout << "graph[curr][i]: " << graph[curr][i] << endl;
        // cout << "Color: " << color[graph[curr][i]] << endl;

        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (color[graph[curr][i]] == 'w')
            {
                // cout << "Dis: " << dis[graph[curr][i]] << endl;
                color[graph[curr][i]] = 'g';
                dis[graph[curr][i]] = dis[curr] + 1;
                if (dis[graph[curr][i]] > max_dis)
                {
                    max_dis = dis[graph[curr][i]];
                    index = graph[curr][i];
                }

                pre[graph[curr][i]] = curr;
                q.push(graph[curr][i]);
            }
        }
        color[curr] = 'b';
    }
    lim--;
    if (lim == 0)
    {
        return max_dis;
    }
    return bfs(graph, index);
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
    cout << bfs(graph, 1) << endl;

    // for (int i = 1; i <= v; i++)
    // {
    //     cout << "Dis: " << dis[i] << " ";
    // }
}
