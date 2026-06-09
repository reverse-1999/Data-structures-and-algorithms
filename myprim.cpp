#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 你把 Prim 算法写在这里。
// graph 用邻接矩阵存图，没边的位置可以自己约定成 0 或 INF。
int prim(const vector<vector<int>> &graph, int start)
{
	if (graph.empty() || start < 0 || start >= graph.size())
	{
        return -1; // 输入无效
	}
    int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> minEdge(n, INT_MAX);
	minEdge[start] = 0;
	visited[start] = true;
	int totalWeight = 0;
	for(int k = 0; k < n - 1; k++)//需要添加 n-1 条边
	{	
		int minIndex = -1;
		for(int i = 0; i < n; i++)//扫描已访问的节点
		{
			if(visited[i])
			{	
				for(int j = 0;j < n; j++)
				{	
					if(graph[i][j] != 0 && !visited[j] && graph[i][j] < minEdge[j]) 
					{
						minEdge[j] = graph[i][j];
					}
				}
			}
		}
		for(int i = 0; i < n; i++)//找到最小边
		{
			if(!visited[i] && minEdge[i] != INT_MAX)
			{
				if(minIndex == -1 || minEdge[i] < minEdge[minIndex])
				{
					minIndex = i;
				}
			}
		}
		if(minIndex != -1)
		{
			visited[minIndex] = true;
			totalWeight += minEdge[minIndex];
		}
	}
	return totalWeight;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (graph[u][v] == 0 || w < graph[u][v])
		{
			graph[u][v] = w;
			graph[v][u] = w;
		}
	}

	int start = 0;
	cin >> start;

	cout << prim(graph, start) << endl;
	return 0;
}
