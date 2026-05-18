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
        // TODO 计算一个有向图中每个节点在遍历过程中可以访问到的节点数
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