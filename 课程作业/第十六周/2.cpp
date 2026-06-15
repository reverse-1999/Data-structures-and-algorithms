#include <iostream>
#include <string>
using namespace std;
string largestOddNumber(string num)
{
    int size = num.size();
    int res = 0;
    for(int i = 0;i < size-1;i++)
    {
        int number = 0;
        for(int j = 1;j <= size-i;j++)
        {
            number = stoi(num.substr(i,j));
            if(number % 2 != 0 && number > res){
                res = number;
            }
        }
    }
    string result = to_string(res);
    if(res == 0) {return "None";}
    return result;
}
int main() {
string num;
cin >> num;
cout << largestOddNumber(num) << endl;
return 0;
}