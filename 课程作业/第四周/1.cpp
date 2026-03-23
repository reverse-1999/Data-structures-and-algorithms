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
		//请完成入栈函数代码
        Node* new_head = new Node;
        new_head->data = elem;
        new_head->next = nullptr;
        size++;
        if(head == nullptr) {head = new_head; return;} 

        new_head->next = head;

        head = new_head;
	};

	void pop() {
		//请完成出栈函数代码
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
	// 请完成符号匹配代码
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