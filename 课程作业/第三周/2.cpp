#include <iostream>
using namespace std;

template <typename T>
struct Node
{ // 定义节点
    Node *next;
    T value;
};

template <typename T>
class List
{ // 定义单向循环链表
public:
    Node<T> *record; // 定义当前操作指针(null)
    int length;
    List() : record(nullptr), length(0){}; // 初始化链表
    ~List() { delete record; }

    void insert(T value)
    /* 
    函数名：insert
    输入值：泛型 value
    功  能：向循环链表中插入一个节点，值为value
     */
    {
        Node<T> *node = new Node<T>; // 新加入节点 node
        node->value = value;         // 新节点 node 赋值
        node->next = nullptr;        // 新节点的 next 节点
        length = length + 1;         // 链表长度增加
        //============================
        if (record == nullptr)
        { // 链表为空，node 作为头节点
            record = node;
            record->next = record; // 循环链表的 next 指向自己
            return;
        }
        node->next = record->next; // node 的 next 指向头节点
        record->next = node;       // record 的 next 指向 node
        record = node;             // record 指向 node，node 成为新的头节点

 
    }

    T pop(int position)
    /* 
    函数名：pop
    输入值：整型 position
    功  能：将position位置的节点进行出队，返回值为该节点
     */
    {
        position = position + length;
        for (int i = 1; i < position; i++) // 通过顺序循环，将当前操作指针移动到被删除节点的前驱
            record = record->next;
        Node<T> *p = record->next;               // p 指向被删除节点
        T temp = p->value;                      // temp 存储被删除节点的值
        record->next = record->next->next;     // 删除节点
        p = nullptr;                       // 智能指针删除节点
        length = length - 1;               // 元素出栈后，链表长度减一
        if (length == 0)
            record = nullptr; // 链表中没有元素，指向空指针
        return temp;
    }

    void printAll()
    /* 
    函数名：printAll
    输入值：无
    功  能：遍历并输出队列
     */
    {
        Node<T> *p = record;
        if (p == nullptr)
        { // 若 record 为空，则链表为空，输出为空
            cout << endl;
            return;
        }
        cout << p->next->value; // 否则输出头指针的值
        p = p->next;           // p 指向头节点
        while (p != record)
        { // 循环输出链表中的元素，直到 p 回到 record
            cout << " " << p->next->value;
            p = p->next;
        }
        cout << endl;
    }
};

template <typename T>
void test()
{
    int length, position, circle;
    T value;
    List<T> mylist;
    cin >> length;
    for (; length > 0; length--)
    {
        cin >> value;
        mylist.insert(value);
    }
    mylist.printAll();
    cin >> position;
    cin >> circle;
    for (int i = 0; i < circle; i++)
    {
        cout << mylist.pop(position) << endl;
    }
    mylist.printAll();
}

int main()
{
    string dtype;
    cin >> dtype;
    if (dtype == "int")
        test<int>();
    else if (dtype == "float")
        test<float>();
    else
        test<char>();
    return 0;
}