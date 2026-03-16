#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    Node *next;
    T value;
};
template <typename T>
class List
{
public:
    Node<T> *head;
    List() : head(nullptr){};
    ~List()
    {
        Node<T> *p;
        while (head != nullptr)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }

    void insert(T value)
    /* 
    函数名：insert
    输入值：泛型 value
    功  能：向队列中插入一个节点，值为value，使得表内元素实现有序排列（从小到大）
     */
    {
        Node<T> *p = head;              //获得头节点指针    
        Node<T> *node = new Node<T>;    //创建新的节点
        node->value = value;
        node->next = nullptr;
        //============================
        if(head == nullptr)
        {
            head = node;
            return;
        }
        if(node->value < head->value)
        {
            node->next = head;
            head = node;
            return;
        }
        while(p->next != nullptr && p->next->value < node->value)
        {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;

        //============================
    }
    void merge(List<T> *l2)
    /* 
    函数名：merge
    输入值：队列地址
    功  能：合并两个线性表
     */
    {
        //============================
        Node<T> *p1 = head;
        Node<T> *p2 = l2->head;
        List<T> *mergedList = new List<T>();
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->value < p2->value)
            {
                mergedList->insert(p1->value);
                p1 = p1->next;
            }
            else
            {
                mergedList->insert(p2->value);
                p2 = p2->next;
            }
        }
        while (p1 != nullptr)
        {
            mergedList->insert(p1->value);
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            mergedList->insert(p2->value);
            p2 = p2->next;
        }
        head = mergedList->head;

        //============================
    }
}