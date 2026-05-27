#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostConnectPoints(vector<vector<int>> &points)
{
    // Prim算法求平面点的最小生成树总权值
    int n = points.size();
    vector<int> minDist(n, 100000); // 每个点到生成树的最小距离
    vector<bool> visited(n, false);
    minDist[0] = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }
        visited[u] = true;
        res += minDist[u];
        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i][0] >> points[i][1];
    }
    // 调用minCostConnectPoints 方法计算结果
    int result = minCostConnectPoints(points);
    cout << result << endl;
    return 0;
}