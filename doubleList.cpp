#include <iostream>
using namespace std;

const int MAXSIZE = 100;
class Deque {

public:
    int arr[MAXSIZE];
    int front;
    int rear;
    Deque() {
        front = 0;
        rear = 0;
    }
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return (rear + 1) % MAXSIZE == front;
    }
    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full." << endl;
        }
        else {
            front = (front - 1 + MAXSIZE) % MAXSIZE;
            arr[front] = x;
        }
    }
    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full." << endl;
        }
        else {
            arr[rear] = x;
            rear = (rear + 1) % MAXSIZE;
        }
    }
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
        }
        else {
            front = (front + 1) % MAXSIZE;
        }
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
        }
        else {
            rear = (rear - 1 + MAXSIZE) % MAXSIZE;
        }
    }
};
int main() {
    //测试四个函数
    Deque dq;
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.deleteFront();
    dq.deleteRear();
    while (!dq.isEmpty()) {
        cout << dq.arr[dq.front] << " ";
        dq.deleteFront();
    }
    return 0;
}