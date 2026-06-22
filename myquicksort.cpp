#include <iostream>
#include <algorithm>
using namespace std;
int Partition(int arr[], int low, int high)
{
    // TODO: 实现快速排序中的划分逻辑
    int pivot = arr[high];
    int l = low;
    int r = high - 1;
    while(l < r)
    {
        if(arr[l]<pivot){
            l++;
        }
        if(arr[r]>=pivot){
            r--;
        }
        if(l < r)
        {
            swap(arr[l],arr[r]);
        }
    }
    
    swap(arr[l],arr[high]);
    return l;
}

// 快速排序
void QuickSort(int arr[], int low, int high)
{
    // TODO: 实现快速排序的递归逻辑
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