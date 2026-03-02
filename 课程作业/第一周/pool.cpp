#include <iostream>
using namespace std;
const float PI = 3.14159 ;
const float Price_1 = 20 ; //栅栏单价
const float Price_2 = 35 ; //水泥单价

class pool {
private:float radius; //池塘半径
	   float fence_cost; //栅栏造价
	   float cement_cost; //水泥造价
public:
	pool(float r) {
		radius = r;
	};
	float calculate_fence_cost() {
		fence_cost = 2 * PI * radius * Price_1;
		return fence_cost;
	};
	float calculate_cement_cost() {
		cement_cost = PI * ((radius+3)*(radius+3)-radius*radius) * Price_2;
		return cement_cost;
	}
};


int main() {
	float radius;
	cin >> radius;
	pool p(radius);
	cout  << p.calculate_fence_cost() << endl;
	cout  << p.calculate_cement_cost() << endl;
    return 0;
}