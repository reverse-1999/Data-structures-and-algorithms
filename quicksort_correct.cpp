#include <iostream>
using namespace std;

// Lomuto 分区法 — 取最后一个元素为基准
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // i 指向第一个 >= pivot 的元素
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{
    int num;
    cin >> num;

    int *a = new int[num];
    for (int i = 0; i < num; i++)
        cin >> a[i];

    QuickSort(a, 0, num - 1);

    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;
    return 0;
}
