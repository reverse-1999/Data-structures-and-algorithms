#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 计算跨越中点的最大子数组和
int crossSum(int nums[], int low, int mid, int high) {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
    
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }
    
        return left_sum + right_sum;
}

// 分治主函数
int maxSubArray(int nums[], int low, int high) {
    if (low == high) {
        return nums[low];
    }
    
    int mid = low + (high - low) / 2;
    
    int left_sum = maxSubArray(nums, low, mid);
    int right_sum = maxSubArray(nums, mid + 1, high);
    int cross_sum = crossSum(nums, low, mid, high);
    
    return max({left_sum, right_sum, cross_sum});
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << maxSubArray(nums, 0, n - 1);
    return 0;
}