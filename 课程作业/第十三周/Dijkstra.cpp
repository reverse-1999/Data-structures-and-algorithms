#include <iostream>
#define MAX_W 10000
using namespace std;

int shortestPath(int N, int M, int E[][3], int v1, int v2)//顶点、边数、边、起始点、终点
{
    int weight[N+1];
    bool P[N+1];
    for(int i = 0; i <= N; i++) {
        weight[i] = MAX_W;
        P[i] = false;
    }
    int start = v1;
    int end = v2;
    weight[start] = 0;

    for(int i = 1; i <= N; i++) {
        int u = -1; 
        int min = MAX_W;
        for(int j = 1; j <= N; j++) {
            if(!P[j] && weight[j] <= min) {
                min = weight[j];
                u = j;
            }
        }
        if(u == -1) break;
        P[u] = true;
        if(u == end) break;

        for(int j = 0; j < M; j++) {
            if(E[j][0] == u) {
                int v = E[j][1];
                if(!P[v] && weight[u] + E[j][2] < weight[v]) {
                    weight[v] = weight[u] + E[j][2];
                }
            }
        }
    }
    if(weight[end] == MAX_W) return -1;
    return weight[end];
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
