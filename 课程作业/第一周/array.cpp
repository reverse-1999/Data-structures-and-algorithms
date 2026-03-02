#include <iostream>
using namespace std;

class Array{

private:

int *data;     //定义整形数据data保存数据

int count;

int n;

public:

//构造函数

Array(int nums){

data=new int[nums];

n=nums;

count=0;

}

void adddata(int x){
    data[count] = x;
    count++;
}

void PrintAll( ){
    int i = 0;
    while(i < n-1)
    {
        cout<<data[i]<<" ";
        i++;
    }
    cout<<data[i]<<endl;

}

void FindMax( ){
    int max = 0;
    for(int i = 0;i<n;i++){
        if(data[i] > max)
        {
            max = (data[i]);
        }
    }
    cout<<max<<endl;
}

void FindMin( ){
    int min = 1000;
    for(int i = 0;i<n;i++){
        if(data[i] <= min)
        {
            min = data[i];
        }
    }
    cout<<min<<endl;
}

void Exchange(int index1, int index2){
    if(index1 >= n || index2 >= n) return;
    if(index1 < 0 || index2 < 0) return;
    int p = data[index1];
    data[index1] = data[index2];
    data[index2] = p;
}

bool Contains(int x){
    for(int i = 0;i<n;i++){
        if(data[i] == x)
        {
            return true;
        }
    }
    return false;
}

};

int main( ){

int length = 0;
cin>>length;
Array array = Array(length);
for(int i = 0;i<length;i++)
{
    int temp = 0;
    cin>>temp;
    array.adddata(temp);
}
int index1,index2;
cin>>index1>>index2;
float e = 1;
cin>>e;

array.PrintAll() ;//打印数组

array.FindMax()  ;//找出最大值

array.FindMin()  ;//找出最小值

array.Exchange(index1,index2) ;//交换两个元素位置
array.PrintAll() ;//打印数组
cout<<array.Contains(e);//某个元素是否存在

return 0;

}