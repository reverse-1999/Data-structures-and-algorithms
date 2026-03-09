#include <iostream>
using namespace std;

int gcd(int x, int y) {
    //---------------此处完成代码-----------------
    int temp;
	while (y != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

int main() {
    //---------------此处完成代码-----------------
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