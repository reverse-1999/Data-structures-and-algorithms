#include <iostream> 
#include <math.h> 
#include <stack> 
#include <string>
using namespace std; 

stack<char> symbol_stack;
stack<int> number_stack;

//从数字栈中取出栈顶的两个数字进行相关运算，结果放入栈中
void math(char f) {
	// 请完成匹配函数代码
    int a = number_stack.top();
    number_stack.pop();
    int b = number_stack.top();
    number_stack.pop();
    switch(f)
    {
        case '+':{ number_stack.push(a+b);break;}
        case '-':{ number_stack.push(b-a);break;}
        case '*':{ number_stack.push(a*b);break;}
        case '/':{ number_stack.push(b/a);break;}
        default: return;
    }
}

int main() {
	string str; 
	getline(cin, str); 
	int n = 0, j = 0, a[10];
	// 请完成主函数代码
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ') continue;
        if(str[i] >= '0' && str[i] <= '9')
        {
            n = n*10 + (str[i] - '0');
        }
        else
        {
            if(n != 0) {number_stack.push(n); n = 0;}
            if(symbol_stack.empty() || symbol_stack.top() == '(') {symbol_stack.push(str[i]); continue;}
            if(str[i] == ')')
            {
                while(symbol_stack.top() != '(')
                {
                    math(symbol_stack.top());
                    symbol_stack.pop();
                }
                symbol_stack.pop();
            }
            else
            {
               if(symbol_stack.top() == '(') {symbol_stack.push(str[i]); continue;}

               if(str[i] == '+' || str[i] == '-') {
                   while(!symbol_stack.empty() && symbol_stack.top() != '(') {
                       math(symbol_stack.top());
                       symbol_stack.pop();
                   }
                   symbol_stack.push(str[i]);
               }
               else if(str[i] == '*' || str[i] == '/') {
                   while(!symbol_stack.empty() && symbol_stack.top() != '(' && (symbol_stack.top() == '*' || symbol_stack.top() == '/')) {
                       math(symbol_stack.top());
                       symbol_stack.pop();
                   }
                   symbol_stack.push(str[i]);
               }
               else {
                   symbol_stack.push(str[i]);
               }
            }   
        } 
    }
    if(n != 0) number_stack.push(n);
    while(!symbol_stack.empty())
    {
        math(symbol_stack.top());
        symbol_stack.pop();
    }
	cout << number_stack.top() << endl;
	return 0;
}
