#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// Node结构用于表示哈夫曼树中的节点
struct Node {
    int value;       // 节点存储的权值
    Node* left;      // 指向左子节点的指针
    Node* right;     // 指向右子节点的指针
    int height;      // 节点的高度，用于处理相等权值的情况
    Node(int v) : value(v), left(nullptr), right(nullptr), height(0) {}
};

// Compare结构用于定义优先队列的比较方式
struct Compare {
    // 重载()操作符，定义比较规则
    bool operator()(Node* a, Node* b) {
        // 首先比较节点的权值，若权值相等则比较高度
        return a->value > b->value || (a->value == b->value && a->height > b->height);
    }
};

// 构建哈夫曼树的函数
Node* buildHuffmanTree(const vector<int>& values) {
    Node* root = nullptr;
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i = 0;i < values.size();i++)
    {
        pq.push(new Node(values[i]));
    }
    while(pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();
        if(pq.empty())
        {
            root = left;
            break;
        }
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->value + right->value);
        parent->left = left;
        parent->right = right;
        parent->height = max(left->height, right->height) + 1;
        pq.push(parent);
    }
    return pq.top();
}

// 中序遍历哈夫曼树，并将遍历结果保存为字符串
void inorderTraversal(Node* root, string& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, result);
    result += to_string(root->value) + " ";  
    inorderTraversal(root->right, result);  
}

// 主函数
int main() {
    int n;  // 存储节点数量
    cin >> n;
    vector<int> values(n);  // 存储所有节点的权值
    for (int i = 0; i < n; ++i) {
        cin >> values[i];  // 输入权值
    }
    Node* root = buildHuffmanTree(values);  // 构建哈夫曼树
    string result;  // 用于存储中序遍历结果
    inorderTraversal(root, result);  // 执行中序遍历
    if (!result.empty()) {
        result.pop_back();  // 移除最后的空格
    }
    cout << result << endl;  // 输出中序遍历结果
    return 0;
}
