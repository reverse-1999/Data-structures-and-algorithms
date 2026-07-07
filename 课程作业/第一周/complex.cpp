#include<iostream>
#include<cstdio>
using namespace std;
class Complex {
public:
    int real;
    int imag;
    // 构造一个带有实部和虚部的复数对象
    Complex(int r, int i)
    {
		real = r;
		imag = i;
    }
    // 重载加法运算符，返回两个复数的和
    Complex operator+(Complex c) {
		Complex temp(0, 0);
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
    }
    // 按常见数学格式输出复数
    void show() {
			if (imag > 0 && real !=0) 
				cout << real << "+" << imag << "i" << endl;
      else if(imag<0 && real != 0)
        cout << real << imag << "i" << endl;
      else if(imag == 0)
        cout<<real;
      else
        cout << imag << "i" << endl;
    }
};
int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Complex c1(x1, y1);
    Complex c2(x2, y2);
    Complex c3 = c1 + c2;
    c3.show();
    
}/////