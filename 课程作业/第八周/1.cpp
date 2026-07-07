#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;
// 使用C++库中提供的数据结构——栈
typedef char ElemType;
typedef struct BtNode
{
    struct BtNode *leftchild;
    struct BtNode *rightchild;
    ElemType data;
} BtNode, *BinaryTree;
struct BtNode *Buynode()
{
    struct BtNode *s = (struct BtNode *)malloc(sizeof(struct BtNode));
    if (NULL == s)
        exit(1);
    memset(s, 0, sizeof(struct BtNode));
    return s;
}

/* 非递归 --先序中序 */
struct BtNode *NiceCreateTreePI(const char *pstr, const char *istr, int n) 
{
    // 根据先序序列的首元素确定根结点，再在中序序列中划分左右子树
    if (n <= 0) return NULL;
    struct BtNode *root = Buynode();
    root->data = pstr[0];
    int i = 0; 
    while (istr[i] != pstr[0]) i++; // 此时istr[i] == pstr[0]
    root->leftchild = NiceCreateTreePI(pstr + 1, istr, i);
    root->rightchild = NiceCreateTreePI(pstr + i + 1, istr + i + 1, n - i - 1);
    return root;
}


//  入栈
void postOrder(BtNode *root)
{
    // 使用显式栈模拟递归后序遍历
    if(root == nullptr) return;
    stack<BtNode*> s;
    BtNode* cur = root;
    BtNode* last = nullptr;
    while(cur != nullptr || !s.empty()) {
        while(cur != nullptr) {
            s.push(cur);
            cur = cur->leftchild;
       }
        BtNode* node = s.top();
        if(node->rightchild == nullptr || node->rightchild == last) {
            cout << node->data << ' ';
            s.pop();
            last = node;
            cur = nullptr;
        } else {
            cur = node->rightchild;
        }
    }
    cout<<endl;
}
int main()
{
    BinaryTree rootPI_r = NULL;
    string x, y;
    cin >> x >> y;
    const char *pstr = &x[0];
    const char *istr = &y[0];
    rootPI_r = NiceCreateTreePI(pstr, istr, sizeof(pstr));
    postOrder(rootPI_r);
    return 0;
}