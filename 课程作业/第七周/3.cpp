#include <queue>
#include <stack>
#include <iostream>
using namespace std;
template < class Type >
    class BinaryTree {
        private: struct Node {
            Node * left;
            Node * right;
            Type data;
            Node(): left(NULL), right(NULL) {}
            Node(Type item, Node * L = NULL, Node * R = NULL): data(item), left(L), right(R) {}
                ~Node() {}
        };
        Node * root;
        public: BinaryTree(): root(NULL) {}
        BinaryTree(const Type & value) {
            root = new Node(value);
        }
        // 完成代码
        void createTree(Type nullvalue) {
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
    };
int main() {
    BinaryTree < int > tree;
    //树的构建， -1 作为没有子节点的标志
    tree.createTree(-1);
    cout << tree.height();
    return 0;
}