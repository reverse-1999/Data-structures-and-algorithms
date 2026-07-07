#include <iostream>

using namespace std;

// 划分函数
int Partition(int arr[], int low, int high)
{
    // 选取最后一个元素作为基准值，左右指针向中间收缩
    int pivot = arr[high];
    int l = low;
    int r = high - 1;
    while(l < r)
    {   
        while(l < r && arr[l] < pivot)
        {
            l++;
        }
        while(l < r && arr[r] >= pivot)
        {
            r--;
        }
        if(l < r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    if(arr[l] < pivot)
    {
        l++;
    }
    int temp = arr[l];
    arr[l] = arr[high];
    arr[high] = temp;
    return l;
}

// 快速排序
void QuickSort(int arr[], int low, int high)
{
    // 递归处理基准值左右两侧的子区间
    if(low < high)
    {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int num;
    cin >> num; // 输入数组的大小

    int *a = (int *)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {
        cin >> a[i]; // 输入数组的元素
    }

    QuickSort(a, 0, num - 1);

    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}