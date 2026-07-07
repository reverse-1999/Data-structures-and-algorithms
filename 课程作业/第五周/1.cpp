#include <iostream>
#include <cstring>

using namespace std;

string reverseString(const string& str) {
    // 从后向前遍历原字符串，逐个追加到结果串中
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed.append(1,str[i]);
    }
    // 返回反转后的新字符串
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