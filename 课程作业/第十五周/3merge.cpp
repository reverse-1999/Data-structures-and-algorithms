#include <iostream>

using namespace std;
void Merge(int arr[], int low, int mid, int high)
{
    // 将左右两个有序区间按大小归并到临时数组中
    // low 为第 1 有序区的第 1 个元素， mid 为第 1 有序区的最后 1 个元素
    int *temp = (int *)malloc(sizeof(int) * (high - low + 1));
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
    free(temp);
}

// 用递归应用二路归并函数实现排序——分治法
void MergeSort(int arr[], int low, int high)
{
    // 分治拆分区间，递归排序后再合并
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main(int argc, char *argv[])
{
    int num;
    cin >> num; // 输入数组的大小

    int *a = (int *)malloc(sizeof(int) * num);
    // int a[num];
    for (int i = 0; i < num; i++)
    {
        cin >> a[i]; // 输入数组的元素
    }

    MergeSort(a, 0, num - 1);

    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}