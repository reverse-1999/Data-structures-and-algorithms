#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 计算跨越中点的最大子数组和
int crossSum(int nums[], int low, int mid, int high) {
    return 0;
}

// 分治主函数
int maxSubArray(int nums[], int low, int high) {
    int n = high-low+1;
    int res = -100;
    int pre = -100;
    for(int i = 0;i<n;i++)
    {
        pre = max(nums[i],pre+nums[i]);
        res = max(res,pre);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << maxSubArray(nums, 0, n - 1);
    return 0;
}