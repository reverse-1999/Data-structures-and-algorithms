#include <iostream>
#include <string>
#include <vector>
//统计字串出现次数
using namespace std;

int countStr(const string& haystack, const string& needle) {
//haystack: 主字符串
//needle: 子字符串
    if (needle.empty()) return 0;
    if (haystack.empty() || needle.size() > haystack.size()) return -1;

    //find next array
    vector<int> next(needle.size());
    next[0] = -1;//子串只有一个元素时，最长公共前后缀长度为0
    int k = -1;//最大公共前后缀长度-1
    for(int j = 1;j < needle.length()-1;j++){
        k = next[j-1];
        while(k >=0 && needle[j] != needle[k+1])
        {
            k = next[k];
        }
        if(needle[j] == needle[k+1]) k++;
        next[j] = k;
    }
    //find end
    //i:主串索引
    //j:子串索引
    int count = 0;
    int i = 0;
    int j = 0;
    while(i < haystack.length()){
        while (i < haystack.length() && j < needle.length()) {
        if (j == 0 || haystack[i] == needle[j]) { i++; j++; }
        else { j = next[j]+1; }
        }
        if (j == needle.length()) {count++; j = 0;}
    }
    return count;
}

int main() {
    string haystack, needle;
    // 请输入主字符串;
    cin >> haystack;
    // 请输入子字符串;
    cin >> needle;
    int count = countStr(haystack, needle);
    cout << count << endl;
    return 0;
}
