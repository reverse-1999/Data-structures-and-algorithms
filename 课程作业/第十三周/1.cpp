#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    // 读取无向图的边
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<pair<int,int>> bridges;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<graph[i].size();j++)
        {
            int u = i;
            int v = graph[i][j];
            // 删除边u-v
            for(int k = 0; k < graph[u].size(); ++k) {
                if (graph[u][k] == v) {
                    graph[u].erase(graph[u].begin() + k);
                    break;
                }
            }
            for(int k = 0; k < graph[v].size(); ++k) {
                if (graph[v][k] == u) {
                    graph[v].erase(graph[v].begin() + k);
                    break;
                }
            }
            // 检查图是否仍然连通
            vector<bool> visited(n, false);
            visited[u] = true;
            vector<int> stack = {u};
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        stack.push_back(neighbor);
                    }
                }
            }
            bool isBridge = false;
            for (int k = 0; k < n; ++k) {
                if (!visited[k]) {
                    isBridge = true;
                    break;
                }
            }
            if (isBridge) {
                //重复元素不记录
                for (const auto& bridge : bridges) {
                    if ((bridge.first == min(u, v) && bridge.second == max(u, v)) ||
                        (bridge.first == max(u, v) && bridge.second == min(u, v))) {
                        isBridge = false;
                        break;
                    }
                }
                if (isBridge) {
                    bridges.push_back({min(u, v), max(u, v)});
                }
            }
            // 恢复边u-v
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }



    // 对桥边结果排序并输出格式 [[u,v],...]
    sort(bridges.begin(), bridges.end());
    cout << "[";
    for (int i = 0; i < bridges.size(); ++i) {
        if (i > 0) cout << ",";
        cout << "[" << bridges[i].first << "," << bridges[i].second << "]";
    }
    cout << "]";
    return 0;
}

