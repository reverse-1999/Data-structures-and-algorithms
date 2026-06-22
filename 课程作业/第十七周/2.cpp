#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int dims[], int n) {
    int dp[n][n]; // dp[i][j] = 计算 A_i 到 A_j 的最小乘法次数
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0; // 单个矩阵的乘法次数为0
    }
    for (int len = 2; len <= n; len++) { // 矩阵链长度
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    int dims[n+1];
    for (int i = 0; i <= n; i++) cin >> dims[i];
    cout << matrixChainOrder(dims, n);
    return 0;
}