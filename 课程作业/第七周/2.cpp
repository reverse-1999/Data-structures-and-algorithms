#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template <typename Type>
struct Node {
    Node* left;
    Node* right;
    Type data;
    Node() : left(NULL), right(NULL) {}
    Node(Type item, Node* L = NULL, Node* R = NULL) : data(item), left(L), right(R) {}
};

template <class Type>
struct StNode {
    Node<Type>* node;
    int TimesPop;
    StNode(Node<Type>* N = NULL) : node(N), TimesPop(0) {}
};

template <class elemType>
class linkStack : public stack<elemType> {
private:
    struct node {
        elemType data;
        node* next;
        node(const elemType& x, node* N = NULL) {
            data = x;
            next = N;
        }
        node() : next(NULL) {}
        ~node() {}
    };
    node* elem;

public:
    linkStack() {
        elem = NULL;
    }

    ~linkStack() {
        //完成代码
    }
};

template <class Type>
class BinaryTree {
public:
    Node<Type>* root;

public:
    BinaryTree() : root(NULL) {}

    BinaryTree(const Type& value) {
        root = new Node<Type>(value);
    }

    ~BinaryTree() {
        clear();
    }

    void clear() {
        //完成代码
    }

    void createTree(Type flag) {
        //完成代码
    }

private:
    void clear(Node<Type>* t) {
        //完成代码
    }
};

template <class Type>
class TreeIterator {
public:
    TreeIterator(const BinaryTree<Type>& BT) : T(BT), current(NULL) {}
    virtual ~TreeIterator() {}

    virtual void First() = 0;
    virtual void operator++() = 0;
    //完成代码

public:
    const BinaryTree<Type>& T;
    Node<Type>* current;
};

template <class Type>
class Preorder : public TreeIterator<Type> {
public:
    Preorder(const BinaryTree<Type>& R) : TreeIterator<Type>(R) {
        if (this->T.root)
            s.push(this->T.root);
    }

    ~Preorder() {}

    void First() {
        //完成代码
    }

    void operator++() {
        //完成代码
    }

protected:
    linkStack<Node<Type>*> s;
};

template <class Type>
class Postorder : public TreeIterator<Type> {
public:
    Postorder(const BinaryTree<Type>& R) : TreeIterator<Type>(R) {
        if (this->T.root)
            s.push(StNode<Type>(this->T.root));
    }

    ~Postorder() {}

    void First() {
        //完成代码
    }

    void operator++() {
        //完成代码
    }

protected:
    linkStack<StNode<Type>> s;
};

template <class Type>
class Inorder : public Postorder<Type> {
public:
    Inorder(const BinaryTree<Type>& R) : Postorder<Type>(R) {}
    void operator++();
};

template <class Type>
void Inorder<Type>::operator++() {
    //完成代码
}

int main() {
    BinaryTree<int> tree;
    tree.createTree(-1);

    Preorder<int> pre(tree);
    for (pre.First(); pre; ++pre)
        cout << pre() << ' ';
    cout << endl;

    Inorder<int> in(tree);
    for (in.First(); in; ++in)
        cout << in() << ' ';
    cout << endl;

    Postorder<int> post(tree);
    for (post.First(); post; ++post)
        cout << post() << ' ';
    cout << endl;

    return 0;
}