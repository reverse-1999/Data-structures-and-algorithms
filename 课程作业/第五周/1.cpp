#include <iostream>
#include <cstring>

using namespace std;

string reverseString(const string& str) {
    // 核心代码开始：创建一个字符数组来存储反转后的字符串
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed.append(1,str[i]);
    }
    // 核心代码结束：将字符数组转换为字符串并返回
    return reversed;
}

int main() {
    string input;
    // 请输入一个字符串
    cin >> input;
    string reversed = reverseString(input);
    cout << reversed;
    return 0;
}