#include <queue>
#include <stack>
#include <iostream>
using namespace std;
template < class Type >
class BinaryTree {
    struct Node {
    Node* left;
    Node* right;
    Type data;
    Node() : left(NULL), right(NULL) {}
    Node(Type item, Node* L = NULL, Node* R = NULL) : data(item), left(L), right(R) {}
    ~Node() {}
};
       Node* root;
public: BinaryTree() : root(NULL) {}
      // 完成代码
      void createTree(Type nullvalue)
      {
          int value;
          queue<Node*> q;
          cin >> value;
          if (value == nullvalue) {
              return;
          }
          root = new Node(value);
          q.push(root);
          while (!q.empty()) {
              Node* node = q.front();
              q.pop();
              cin >> value;
              if (value != nullvalue) {
                  node->left = new Node(value);
                  q.push(node->left);
              }
              cin >> value;
              if (value != nullvalue) {
                  node->right = new Node(value);
                  q.push(node->right);
              }
          }
      }
      int height() {
          if (root == nullptr) {
              return 0;
          }
          int h = 0;
          queue<Node*> q;
          q.push(root);
          while (!q.empty()) {
              int size = q.size();
              for (int i = 0; i < size; i++) {
                  Node* node = q.front();
                  q.pop();
                  if (node->left) {
                      q.push(node->left);
                  }
                  if (node->right) {
                      q.push(node->right);
                  }
              }
              h++;
          }
          return h;
      }
      int size() {
          if (root == nullptr) {
              return 0;
          }
          int s = 0;
          queue<Node*> q;
          q.push(root);
          while (!q.empty()) {
              int size = q.size();
              for (int i = 0; i < size; i++) {
                  Node* node = q.front();
                  q.pop();
                  s++;
                  if (node->left) {
                      q.push(node->left);
                  }
                  if (node->right) {
                      q.push(node->right);
                  }
              }
          }
          return s;
      }
      void makeTree(Type value, BinaryTree& leftTree, BinaryTree& rightTree) {
          root = new Node(value, leftTree.root, rightTree.root);
          leftTree.root = nullptr;
          rightTree.root = nullptr;
      }
      void preOrder() {//前序遍历
        if(root == nullptr) {
            return;
        }
        stack<Node*> s;
        Node* cur = root;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                cout << cur->data << ' ';
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        cout<<endl;
      }
      void midOrder() {//中序遍历
        if(root == nullptr) {
            return;
        }
        stack<Node*> s;
        Node* cur = root;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                cout << cur->data << ' ';
                cur = cur->right;
            }
        }
        cout<<endl;
      }
      void postOrder() {//后序遍历
        if(root == nullptr) return;
        stack<Node*> s;
        Node* cur = root;
        Node* last = nullptr;
        while(cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            Node* node = s.top();
            if(node->right == nullptr || node->right == last) {
                cout << node->data << ' ';
                s.pop();
                last = node;
                cur = nullptr;
            } else {
                cur = node->right;
            }
        }
        cout<<endl;
      }

};


int main() {
    int x;
    BinaryTree < int > tree, tree1, tree2;
    //第一颗树的构建，-1 作为没有子节点的标志
    tree.createTree(-1);
    cout << tree.height() << ' ' << tree.size() << endl;

    //第二颗树的构建
    tree1.createTree(-1);
    cout << tree1.height() << ' ' << tree1.size() << endl;

    //合并两棵树，x 为根节点的值
    cin >> x;
    tree2.makeTree(x, tree, tree1);
    cout << tree2.height() << ' ' << tree2.size() << endl;
    tree2.preOrder();
    tree2.midOrder();
    tree2.postOrder();
    return 0;
}