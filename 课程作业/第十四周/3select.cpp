#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

template<typename T>
void SelectSort(vector<T> &a, int n)
{
    // 请实现排序部分代码
    for(int i = 0;i<n-1;i++)//扫描次数
    {
        int min = i;//最小下标
        for(int j = i+1;j<n;j++)//扫描
        {
            if(a[j] < a[min])
            {
                min = j;
            }

        }
            //T temp = a[i];
            //a[i] = a[min];
            //a[min] = temp;
            swap(a[i],a[min]);
    }
}

int main() {
    vector<int> vec;
    int temp;
    while (cin >> temp) {
        vec.push_back(temp);
        if (cin.get() == '\n')
        break;
    }

    SelectSort(vec, vec.size());
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << " " << vec[i];
    }
    cout << endl;
    //return 0;
}