#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> dfsRes, bfsRes;
vector<bool> visited;

// 深度优先遍历，按邻接表中的顺序递归访问可达顶点
void dfs(int u, const vector<vector<int>> &adj)
{
    // 标准 DFS：先标记当前点，再递归访问所有未访问邻接点
    int n = adj.size();
    visited[u] = 1;
    dfsRes.push_back(u);
    for(int v : adj[u])
    {
        if(visited[v] != 1)
        dfs(v,adj);
    }
}

// 广度优先遍历，从 0 号顶点开始分层访问
void bfs(const vector<vector<int>> &adj)
{
    // 标准 BFS：用队列按层次扩展所有可达顶点
    int n = adj.size();
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        bfsRes.push_back(u);
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 邻接表排序保证 DFS 和 BFS 的访问顺序稳定
    for (auto &list : adj)
        sort(list.begin(), list.end());
    visited.assign(n, false);
    dfs(0, adj);
    visited.assign(n, false);
    bfs(adj);
    for (int i = 0; i < dfsRes.size(); ++i)
        cout << (i ? " " : "") << dfsRes[i];
    cout << endl;
    for (int i = 0; i < bfsRes.size(); ++i)
        cout << (i ? " " : "") << bfsRes[i];
}