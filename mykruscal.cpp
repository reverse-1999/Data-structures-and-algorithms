#include <iostream>
#include <vector>
using namespace std;

int kruskal(const vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<vector<int>> e;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (graph[i][j])
				e.push_back({graph[i][j], i, j});
	for (int i = 0; i < e.size(); ++i)
		for (int j = 0; j < e.size() - 1; ++j)
			if (e[j][0] > e[j + 1][0])
			{
				vector<int> t = e[j];
				e[j] = e[j + 1];
				e[j + 1] = t;
			}
	vector<int> p(n);
	for (int i = 0; i < n; ++i) p[i] = i;
	int w = 0, c = 0;
	for (int k = 0; k < e.size(); ++k)
	{
		int u = e[k][1], v = e[k][2];
		// 找 u 的根
		int ru = u;
		while (p[ru] != ru) ru = p[ru];
		// 找 v 的根
		int rv = v;
		while (p[rv] != rv) rv = p[rv];

		if (ru != rv)
		{
			p[rv] = ru;
			w += e[k][0];
			if (++c == n - 1) break;
		}
	}
	return c == n - 1 ? w : -1;
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
	cout << kruskal(graph) << endl;
	return 0;
}
