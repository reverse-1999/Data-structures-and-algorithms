#include <iostream>

using namespace std;

// 冒泡排序
void BubbleSort(int arr[], int n)
{
    // 通过不断比较相邻元素，把较小值逐步交换到前面
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i] < arr[j])
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
