#include<iostream>
using namespace std;

void shellSort(int a[], int n)  //a -- 待排序的数组, n -- 数组的长度
{
    int i, j, gap;   // gap为步长，每次减为原来的一半。
    gap = n / 2;//升序
    while(gap > 0)
    {
        for(i = gap;i<n;i+=gap)
        {
            int temp = a[i];
            for(j = i - gap; j >= 0 && a[j] > temp; j -= gap)
            {
                a[j + gap] = a[j];
            }
            a[j + gap] = temp;
        }
        gap /= 2;
    }
    // 请实现希尔排序
}

int main()
{
    int N;
    std::cin >> N;
    int* array = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    shellSort(array, N);
    for (int i = 0; i < N; i++) {
        std::cout << array[i];
        if (i != (N - 1)) std::cout << " ";
        else std::cout << std::endl;
    }
    return 0;
}