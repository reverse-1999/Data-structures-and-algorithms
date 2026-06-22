#include <iostream>
#include <algorithm>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
    int dp[4 + 1][50 + 1]; // dp[i][w] = 前i个物品在容量w下的最大价值
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            dp[i][j] = 0;
            
        }
    }
    for (int i = 0; i < n; i++) //第i个物品
    {
        for (int j = 0; j < W+1; j++) //容量j下
        {
            if (wt[i] > j) //如果第i个物品的重量大于当前容量j，则不能放入背包
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - wt[i]] + val[i]); 
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;
    int wt[100], val[100];
    for (int i = 0; i < n; i++) cin >> wt[i];
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << knapSack(W, wt, val, n);
    return 0;
}