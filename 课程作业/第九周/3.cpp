#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 多叉树节点
struct MultiTreeNode
{
    int data;
    vector<int> children;
};

// 二叉树节点
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr)
    {
    }
};

// 从用户输入读取多叉树
vector<MultiTreeNode> readMultiTree(int n)
{
    vector<MultiTreeNode> tree(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tree[i].data;
        int numChildren;
        cin >> numChildren;
        for (int j = 0; j < numChildren; ++j)
        {
            int childIndex;
            cin >> childIndex;
            tree[i].children.push_back(childIndex);
        }
    }
    return tree;
}

BinaryTreeNode *convertMultiToBinary(vector<MultiTreeNode> &multiTree,int index)
{
    // 左孩子指向第一个子结点，右孩子串接同层的兄弟结点
    BinaryTreeNode *root = new BinaryTreeNode(multiTree[index].data);
    if(multiTree[index].children.empty()) return root;
    root->left = convertMultiToBinary(multiTree, multiTree[index].children[0]);
    BinaryTreeNode *cur = root->left;
    for(int i = 1;i < multiTree[index].children.size();i++)
    {
        cur->right = convertMultiToBinary(multiTree, multiTree[index].children[i]);
        cur = cur->right;
    }
    return root;
}

// 打印二叉树（层序遍历）
void printBinaryTree(BinaryTreeNode *root)
{
    if (!root)
        return;
    stack<BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode *node = q.top();
        q.pop();
        cout << node->data << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

// 释放二叉树内存
void freeBinaryTree(BinaryTreeNode *root)
{
    if (!root)
        return;
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    delete root;
}

int main()
{
    int n;
    cin >> n;
    vector<MultiTreeNode> multiTree = readMultiTree(n);
    BinaryTreeNode *binaryTree = convertMultiToBinary(multiTree, 0);
    printBinaryTree(binaryTree);
    freeBinaryTree(binaryTree);
    return 0;
}