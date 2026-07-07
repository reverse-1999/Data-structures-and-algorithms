#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//邻接矩阵转邻接表
int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    // 扫描邻接矩阵，把每一行的边信息转存到邻接表中
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int edge;
            cin >> edge;
            if(edge == 1) {
                adjList[i].push_back(j);
            }
        }
    }    
    // 按顶点编号顺序输出，便于检查转换结果
    for(int i = 0; i < n; i++) {
        sort(adjList[i].begin(), adjList[i].end());
        cout << i << " ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if(j != adjList[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}