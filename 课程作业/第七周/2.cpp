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
        while (elem) {
            node* tmp = elem;
            elem = elem->next;
            delete tmp;
        }
    }

    void push(const elemType& x) {
        elem = new node(x, elem);
    }

    void pop() {
        if (elem) {
            node* tmp = elem;
            elem = elem->next;
            delete tmp;
        }
    }

    elemType& top() {
        return elem->data;
    }

    bool empty() const {
        return elem == NULL;
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
        clear(root);
        root = NULL;
    }

    void createTree(Type flag) {
        queue<Node<Type>**> q;
        q.push(&root);
        Type val;
        while (!q.empty()) {
            Node<Type>** p = q.front();
            q.pop();
            cin >> val;
            if (val == flag) {
                *p = NULL;
            } else {
                *p = new Node<Type>(val);
                q.push(&((*p)->left));
                q.push(&((*p)->right));
            }
        }
    }

private:
    void clear(Node<Type>* t) {
        if (!t) return;
        clear(t->left);
        clear(t->right);
        delete t;
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
    virtual operator bool() const { return current != NULL; }
    virtual Type operator()() const { return current->data; }
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
        while (!s.empty()) s.pop();
        if (this->T.root)
            s.push(this->T.root);
        operator++();
    }

    void operator++() {
        if (s.empty()) {
            this->current = NULL;
            return;
        }
        this->current = s.top();
        s.pop();
        if (this->current) {
            if (this->current->right) s.push(this->current->right);
            if (this->current->left) s.push(this->current->left);
        }
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
        while (!s.empty()) s.pop();
        if (this->T.root)
            s.push(StNode<Type>(this->T.root));
        operator++();
    }

    void operator++() {
        this->current = NULL;
        while (!s.empty()) {
            StNode<Type>& topNode = s.top();
            if (topNode.TimesPop == 0) {
                topNode.TimesPop++;
                if (topNode.node->left)
                    s.push(StNode<Type>(topNode.node->left));
            } else if (topNode.TimesPop == 1) {
                topNode.TimesPop++;
                if (topNode.node->right)
                    s.push(StNode<Type>(topNode.node->right));
            } else {
                this->current = topNode.node;
                s.pop();
                break;
            }
        }
    }

protected:
    linkStack<StNode<Type>> s;
};

template <class Type>
class Inorder : public Postorder<Type> {
public:
    Inorder(const BinaryTree<Type>& R) : Postorder<Type>(R) {}
    void First() {
        while (!this->s.empty()) this->s.pop();
        Node<Type>* p = this->T.root;
        while (p) {
            this->s.push(StNode<Type>(p));
            p = p->left;
        }
        operator++();
    }
    void operator++();
};

template <class Type>
void Inorder<Type>::operator++() {
    this->current = NULL;
    if (this->s.empty()) return;
    StNode<Type> topNode = this->s.top();
    this->s.pop();
    this->current = topNode.node;
    Node<Type>* p = topNode.node->right;
    while (p) {
        this->s.push(StNode<Type>(p));
        p = p->left;
    }
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