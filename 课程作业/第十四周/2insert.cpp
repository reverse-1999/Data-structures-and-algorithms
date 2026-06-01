#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

template<typename T>
void InsertSort(vector<T> &a, int n)
{
    // 请实现排序部分代码
    for(int i = 1;i<n;i++)
    {
        T temp = a[i];
        while(i > 0 && a[i-1] > temp)
        {
            a[i] = a[i-1];
            i--;
        }
        a[i] = temp;
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

    InsertSort(vec, vec.size());
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << " " << vec[i];
    }
    cout << endl;
    //return 0;
}