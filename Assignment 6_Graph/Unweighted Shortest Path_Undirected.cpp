#include <bits/stdc++.h>
using namespace std;
#define inf 100000000
char color[1000];
int pre[1000];
int dis[1000];
int bfs(vector<int> graph[], int v, int e, int s, int d)
{
    for (int i = 1; i <= v; i++)
    {
        color[i] = 'w';
        pre[i] = -1;
        dis[i] = inf;
    }
    color[s] = 'g';
    dis[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        // cout << "Q: " << curr << endl;
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++)
        {
            // cout << "graph[curr][i]: " << graph[curr][i] << endl;
            // cout << "Color: " << color[graph[curr][i]] << endl;
            if (color[graph[curr][i]] == 'w')
            {
                color[graph[curr][i]] = 'g';
                dis[graph[curr][i]] = dis[curr] + 1;
                pre[graph[curr][i]] = curr;
                // cout << "Dis: " << dis[graph[curr][i]] << endl;
                q.push(graph[curr][i]);
            }
        }
        color[curr] = 'b';
    }
    return dis[d];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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
    int p, q;
    cin >> p >> q;
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
    cout << bfs(graph, v, e, p, q) << endl;
}