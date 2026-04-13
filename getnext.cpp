#include <iostream>
#include <string>
#include <vector>
using namespace std;
void getnext(const string& needle) {

//needle: 子字符串
    if (needle.empty()) return;
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
    for(int i = 0;i<next.size();i++){
        cout << next[i] << " ";
    }
    cout << endl;
}
int main() {
    string needle;
    // 请输入子字符串;
    cin >> needle;
    getnext(needle);
    return 0;
}
