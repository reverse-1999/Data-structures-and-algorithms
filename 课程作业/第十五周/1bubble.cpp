#include <iostream>

using namespace std;

// 冒泡排序
void BubbleSort(int arr[], int n)
{
    // TODO: 实现冒泡排序逻辑
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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

    BubbleSort(a, num);

    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
