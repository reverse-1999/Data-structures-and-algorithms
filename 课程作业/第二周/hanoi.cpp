#include <iostream>
using namespace std;

// 递归函数：将 n 个盘子从 from 塔移动到 to 塔，aux 为辅助塔
void hanoi(int n, char from, char aux, char to) {
	// 规模为 1 时直接输出移动步骤，否则先借助辅助塔搬运上面 n-1 个盘子
	if (n == 1) {
		cout << "Move disk 1 from " << from << " to " << to << endl;
		return;
	}
	hanoi(n - 1, from, to, aux); 
	cout << "Move disk " << n << " from " << from << " to " << to << endl; 
	hanoi(n - 1, aux, from, to);
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}