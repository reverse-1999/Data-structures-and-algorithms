#include <iostream>
#define MAX_W 10000
using namespace std;

int shortestPath(int N, int M, int E[][3], int v1, int v2)//顶点、边数、边、起始点、终点
{
    int weight[N];
    int P[N];//未访问
    int Q[N];//已访问
    for(int i = 0;i<N;i++)
    {
        weight[i] = MAX_W;
        P[i] = 1;
        Q[i] = 0; 
    }
    int points_now = v1;
    weight[v1] = 0;
    while(1)
    {
        P[points_now] = 0;
        Q[points_now] = 1;
        int min = MAX_W;
        for(int i = 0;i<N;i++)
        {
            if(Q[i] == 1)
            {
                for(int j = 0;j<M;j++)
                {
                    if(E[j][0] == i && P[E[j][1]] == 1)
                    {
                        if(weight[i] + E[j][2] < weight[E[j][1]])
                        {
                            weight[E[j][1]] = weight[i] + E[j][2];
                            if(weight[E[j][1]] <= min)
                            {
                                min = weight[E[j][1]];
                                points_now = E[j][1];
                            }
                        }
                    }

                }
            }
        }

        // 全局最小未处理节点选择：如果没有新的松弛导致选择，做一次全局扫描
        int next = -1;
        int best = MAX_W;
        for (int i = 0; i < N; ++i) {
            if (P[i] == 1 && weight[i] < best) {
                best = weight[i];
                next = i;
            }
        }
        if (next == -1) {
            // 没有可达的未处理节点，返回不可达或当前目标距离
            return (weight[v2] == MAX_W) ? -1 : weight[v2];
        }
        points_now = next;

        if(points_now == v2)
        {
            return weight[v2];
        }
    }
}
int main()
{
    int N, M, v1, v2;
    cin >> N >> M >> v1 >> v2;
    int (*E)[3] = new int[M][3]; //  E[i][0]：顶点a， E[i][1]：顶点b， E[i][2]：a到b的距离
    for (int i = 0; i < M; i++)
        cin >>E[i][0] >> E[i][1] >> E[i][2];
    cout << shortestPath(N, M, E, v1, v2);
    return 0;
}
