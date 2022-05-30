#include <bits/stdc++.h>
using namespace std;
#define inf 100000000
int v, e;
char color[1000];
int pre[1000];
int fin[1000];
int dis[1000];
vector<int> st;
int t = 0;
// void print_stack(int lim)
// {
//     cout << st.top() << " ";
//     st.pop();
//     while (st.top() != lim)
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }

int check(int key)
{
    int low = 0, high = st.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (st[mid] == key)
        {
            return mid;
        }
        else if (st[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void dfs_visit(vector<int> graph[], int src)
{
    color[src] = 'g';
    // st.push(src);
    st.push_back(src);
    t++;
    dis[src] = t;
    for (int i = 0; i < (int)graph[src].size(); i++)
    {
        if (color[graph[src][i]] == 'g' && check(graph[src][i]) != -1)
        {
            cout << "YES" << endl;
            // print_stack(graph[src][i]);
            return;
        }

        if (color[graph[src][i]] == 'w')
        {
            pre[graph[src][i]] = src;
            cout << "  " << graph[src][i];
            dfs_visit(graph, graph[src][i]);
        }
    }
    // cout << endl;
    color[src] = 'b';
    t++;
    fin[src] = t;
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
    for (int i = 1; i <= v; i++)
    {
        if (color[i] == 'w')
        {
            dfs_visit(graph, i);
        }
    }
}
int main()
{
    cin >> v >> e;
    int x, y;
    vector<int> graph[v + 1];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= v; i++)
    {
        cout << "vertex " << i;
        for (int j = 0; j < (int)graph[i].size(); j++)
        {
            cout << " --> " << graph[i][j];
        }
        // cout << graph[i].size() << endl;
        cout << endl;
    }
    dfs(graph);
    cout << endl;
    for (int i = 1; i <= v; i++)
    {
        if (color[i] == 'b')
        {
            cout << "visited: " << i << ", Dis: " << dis[i] << ", Fin: " << fin[i] << endl;
        }
    }
}