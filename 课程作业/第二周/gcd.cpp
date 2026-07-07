#include <iostream>
using namespace std;

int gcd(int x, int y) {
    // 使用欧几里得算法迭代求最大公约数
    int temp;
	while (y != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

int main() {
    // 读入多组数据并逐行输出结果
    int N = 0;
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    system("pause");
    return 0;
}