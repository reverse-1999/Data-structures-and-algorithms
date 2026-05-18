#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Graph
{
private:
    int V;                   // 顶点的数量
    vector<vector<int>> adj; // 邻接表
    vector<int> disc;        // 已访问顶点的发现时间
    vector<int> low;         // 从子树可以到达的最早访问的顶点（最小发现时间）
    vector<bool> inStack;    // 节点是否在栈中
    stack<int> st;           // 用于存储所有连接节点的栈
    int time;                // 时间计数器
    int sccCount;            // 强连通分量的数量
    void SCCUtil(int u)
    {
        // TODO 完成强连通分量的计算
        disc[u] = low[u] = time++;
        st.push(u);
        inStack[u] = true;
        for (int v : adj[u])
        {
            if (disc[v] == -1)
            {
                SCCUtil(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (low[u] == disc[u])
        {
            while (st.top() != u)
            {
                inStack[st.top()] = false;
                st.pop();
            }
            inStack[st.top()] = false;
            st.pop();
            sccCount++;
        }
        
    }

public:
    Graph(int V) : V(V), adj(V), disc(V, -1), low(V, -1), inStack(V, false), time(0),
                   sccCount(0) {}
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    int SCC()
    {
        for (int i = 0; i < V; ++i)
        {
            if (disc[i] == -1)
            {
                SCCUtil(i);
            }
        }
        return sccCount;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1); // 假设输入是从 1 开始的索引
    }
    cout << g.SCC() << endl;
    return 0;
}