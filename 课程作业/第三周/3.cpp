#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 删除倒数第 n 个结点，先找到链表长度再定位前驱
    if(head == nullptr) {return nullptr;}
    int length = 1;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(p1->next != nullptr)
    {
        p1 = p1->next;
        length++;
    }
    for(int i = 0;i<length-n-1;i++)
    {
        p2 = p2->next;
    }
    p1 = p2;
    p2 = p2->next;
    p1->next = p2->next;
    delete(p2);
    return head;
}
// 辅助函数：创建链表
ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    if (!head) {
        cout << "NULL" << endl;
        return;
    }
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, size;
    cin >> n;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    ListNode* head = createList(arr, size);
    ListNode* result = removeNthFromEnd(head, n);
    printList(result);
    delete[] arr;
    return 0;
}
