//学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。
//餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个栈里，每一轮：
//如果队列最前面的学生喜欢栈顶的三明治，那么会拿走它并离开队列，否则，这名学生会 放弃这个三明治 并回到队列的尾部。
//这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // 请在此处完善算法，计算无法吃到三明治的学生数量
        int count0 = 0, count1 = 0;
        for (int student : students) {  
            if (student == 0) {
                count0++;
            } else {
                count1++;
            }
        }
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 > 0) {
                    count0--;
                } else {
                    break; // 没有喜欢圆形三明治的学生了
                }
            } else {
                if (count1 > 0) {
                    count1--;
                } else {
                    break; // 没有喜欢方形三明治的学生了
                }
            }
        }
        return count0 + count1; // 返回无法吃到三明治的学生数量
    }
};

// 解析输入的字符串为整数数组
vector<int> parseLine(const string& line) {
    vector<int> res;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    Solution sol;
    string line1, line2;
    
    // 循环读取输入直到文件结束
    while (getline(cin, line1)) { // 读取学生数组
        if (!getline(cin, line2)) { // 读取三明治数组
            break; // 输入不完整则退出
        }
        
        vector<int> students = parseLine(line1);
        vector<int> sandwiches = parseLine(line2);
        
        int result = sol.countStudents(students, sandwiches);
        cout << result << endl;
    }
    
    return 0;
}