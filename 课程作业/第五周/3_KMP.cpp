#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(const string& haystack, const string& needle) {
// 先构造 next 数组，再用 KMP 在主串中查找匹配位置
    if (needle.empty()) return 0;
    if (haystack.empty() || needle.size() > haystack.size()) return -1;

    //find next array
    vector<int> next(needle.size());
    next[0] = -1;
    int k = -1;
    for (int j = 0; j < static_cast<int>(needle.length()) - 1; j++) {
        while (k != -1 && needle[j] != needle[k]) k = next[k];
        k++;
        next[j + 1] = k;
    }

    //find end
    int i = 0;
    int j = 0;
    while (i < static_cast<int>(haystack.length()) && j < static_cast<int>(needle.length())) {
        if (j == -1 || haystack[i] == needle[j]) { i++; j++; }
        else { j = next[j]; }
    }
    if (j == static_cast<int>(needle.length())) return i - j;
    return -1;
    
// 匹配成功时返回起始索引，失败返回 -1

}

int main() {
    string haystack, needle;
    // 请输入主字符串;
    cin >> haystack;
    // 请输入子字符串;
    cin >> needle;
    int index = strStr(haystack, needle);
    if (index != -1) {
       // 子字符串在主字符串中的起始索引为 
        cout << index << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}