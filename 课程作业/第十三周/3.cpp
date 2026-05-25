#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostConnectPoints(vector<vector<int>> &points)
{
    
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