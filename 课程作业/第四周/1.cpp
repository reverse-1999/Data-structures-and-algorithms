#include <iostream>
#include <string>
#include <map>
using namespace std;

class Mystack {
private:
	struct Node
	{
		char data;
		Node *next;
	};

public:
	Node *head; //栈顶指针 
	int size; //栈大小

	Mystack()
	{
		head = nullptr;
		size = 0;
	}; //初始化空间

	~Mystack()
	{
		Node* q = new Node;
		while (head != nullptr)
		{
			q = head;
			head = head->next;
			delete q;
		}
	} //回收栈空间

	void push(char elem) {
		// 将新结点压入栈顶，空栈时直接作为头结点
        Node* new_head = new Node;
        new_head->data = elem;
        new_head->next = nullptr;
        size++;
        if(head == nullptr) {head = new_head; return;} 

        new_head->next = head;

        head = new_head;
	};

	void pop() {
		// 弹出栈顶结点并释放内存
        if(head == nullptr) return;
        else{
            Node* p = head;
            head = head->next;
            delete p;
            size--;
        }
        
	};
};

bool Symbol_matching(string str){
	Mystack stack;
	map<char, char> dic = { {'}','{'}, {']','['}, {')','('} };
	// 遇到左括号入栈，遇到右括号则检查栈顶是否与之匹配
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') stack.push(str[i]);
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            if(stack.head == nullptr) return false;
            else if(stack.head->data == dic[str[i]]) stack.pop();
            else return false;
        }
    }
    if(stack.head == nullptr) return true;
    else return false;

};

int main() { 
	string str;
	bool R; 
	getline(cin, str);
	R = Symbol_matching(str); 
	cout << R << endl; 
	return 0; 
}