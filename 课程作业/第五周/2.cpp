#include <iostream>
#include <string>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void countCharacters(const string& str) {

    // 统计字符频次，并维护按 ASCII 升序的输出顺序
    string char_str;
    vector<int> num;
    for (int i = 0; i < str.length() ; i++)
    {
        if (char_str.empty()) {
            char_str.append(1, str[i]); num.push_back(1);
        }
        else
        {
            int pos = 0;
            int j = 0;
            for (j = 0; j <= char_str.length() - 1; j++)
            {
                if (char_str[j] == str[i]) { num[j] += 1; break; }
            }
            
            if (j == char_str.length())
            {
                while (char_str[pos] < str[i] && pos < char_str.length())
                {
                    pos++;
                }
                char_str.insert(pos, 1, str[i]);
                num.insert(num.begin() + pos, 1);
            }
        }
        }
        for (int k = 0; k < char_str.length(); k++)
        {
            cout << char_str[k] << ':' << num[k] << endl;
        }
        // 逐行输出字符及其出现次数
    }

    int main() {
        string input;
        //请输入一个字符串
        cin >> input;
        countCharacters(input);
        return 0;
    }