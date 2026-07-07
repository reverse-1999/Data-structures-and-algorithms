#include <iostream>
#include <cmath>

using namespace std;

int MaxSubseqSum1(int a[], int n)
{
    int ThisSum, MaxSum = 0;
    // 使用动态规划，dp[i] 表示以 a[i] 结尾的最大连续子段和
    int dp[10];
    dp[0] = a[0];
    for(int i = 1;i<n;i++)
    {
        dp[i] = max(a[i],dp[i-1]+a[i]);
        MaxSum = max(dp[i],MaxSum);
    }
    

    return MaxSum;
}

int main()
{
    // 读取输入并调用最大子段和函数
    int n = 0;
    cin>>n;
    int a[100];
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int MaxSum1 = MaxSubseqSum1(a, n);

    cout << MaxSum1 << endl;

    system("pause");
    return 0;
}