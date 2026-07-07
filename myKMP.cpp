#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(const string& haystack, const string& needle) {
// 核心代码开始：遍历主字符串，寻找匹配的起始位置
//haystack: 主字符串
//needle: 子字符串
    if (needle.empty()) return 0;
    if (haystack.empty() || needle.size() > haystack.size()) return -1;

    //find next array
    vector<int> next(needle.size());
    next[0] = -1;//子串只有一个元素时，最长公共前后缀长度为0
    int k = -1;//最大公共前后缀长度-1
    for(int j = 1;j < needle.length();j++){
        k = next[j-1];
        while(k >=0 && needle[j] != needle[k+1])//在有最大公共前后缀长度的情况下，当前字符不匹配时，回退到上一个最大公共前后缀长度
        {
            k = next[k];//
        }
        if(needle[j] == needle[k+1]) k++;
        next[j] = k;
    }
    //find end

    int i = 0;
    int j = 0;
    while (i < haystack.length() && j < needle.length()) {
        if (j == -1 || haystack[i] == needle[j]) { i++; j++; }
        else if (j == 0) {j = -1;}  
        else { j = next[j-1]+1; }
    }
    if (j == needle.length()) return i - j;
    return -1;
    
// 核心代码结束：如果匹配成功，返回起始索引
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