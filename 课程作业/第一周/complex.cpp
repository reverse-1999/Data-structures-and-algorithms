#include<iostream>
#include<cstdio>
using namespace std;
class Complex {
public:
    int real;
    int imag;
    // 请完成构造函数
    Complex(int r, int i)
    {
		real = r;
		imag = i;
    }
    // 请完成运算符重载
    Complex operator+(Complex c) {
		Complex temp(0, 0);
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
    }
    // 请完成输出函数
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