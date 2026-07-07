#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution
{
public:
    vector<int> countVisitedNodes(vector<int> &g)
    {
        // 逐点模拟沿出边走访，统计从每个起点能访问到的节点数量
        int n = g.size();
        vector<int> result(n);
        for(int i = 0;i < n;i++)
        {
             vector<int> label(n);
            int nownode = i;
            while(label[nownode] != 1)
            {
                label[nownode] = 1;
                nownode = g[nownode];
                result[i]++;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> edges[i];
    }

    vector<int> result = sol.countVisitedNodes(edges);

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}