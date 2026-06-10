#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// graph 用邻接矩阵存图，没边的位置可以自己约定成 0 或 INF。
int kruskal(const vector<vector<int>> &graph, int start)
{
	
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

	cout << kruskal(graph, start) << endl;
	return 0;
}
