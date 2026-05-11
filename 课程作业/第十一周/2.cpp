#include <stdio.h>  
#include <stdlib.h> 

int main() {
    int n, m;
    scanf("%d %d", &n, &m); 

    int *degree = (int*)calloc(n, sizeof(int)); // 动态分配度数数组（替代vector）
    
    // 统计度数
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }

    // 统计奇数度顶点数量
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) {
            odd_count++;
        }
    }


    // 输出结果
    // 欧拉路径存在的度数条件：
    // （注意：因理论学习进度所限，本题目未要求检查图是否连通，理论不严谨但符合题目简化要求）

    if (odd_count == 0 || odd_count == 2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(degree); // 释放内存
    return 0;
}