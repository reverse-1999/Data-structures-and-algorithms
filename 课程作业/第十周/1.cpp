#include <iostream>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> children;
    Node(int _val) : val(_val) {}
};

// 前序遍历
void preorder(Node* root, std::vector<int>& res) {
    if(root == nullptr) {return;}
    res.push_back(root->val);
    for(int i = 0;i<root->children.size();i++)
    {
        preorder((root->children)[i],res);
    }
}

// 后序遍历
void postorder(Node* root, std::vector<int>& res) {
    if(root == nullptr) {return;}
    if(root->children.size() == 0) {
        res.push_back(root->val);
        return;
    }
    for(int i = 0;i<root->children.size();i++)
    {
        postorder((root->children)[i],res);
    }
    res.push_back(root->val);
}


// 递归释放内存
void freeTree(Node* root) {
    if (!root) return;
    for (auto ch : root->children) {
        freeTree(ch);
    }
    delete root;
}

// 创建 N 叉树，遇到输入结束返回 nullptr
Node* createNTree() {
    int val, cnt;
    if (!(std::cin >> val >> cnt)) {
        return nullptr;
    }
    Node* root = new Node(val);
    for (int i = 0; i < cnt; i++) {
        Node* child = createNTree();
        if (child) {
            root->children.push_back(child);
        }
    }
    return root;
}

int main() {
    // 构造树
    Node* root = createNTree();
    if (!root) return 0;

    // 前序
    std::vector<int> pre;
    preorder(root, pre);
    for (size_t i = 0; i < pre.size(); i++) {
        std::cout << pre[i] << (i + 1 < pre.size() ? ' ' : '\n');
    }

    // 后序
    std::vector<int> post;
    postorder(root, post);
    for (size_t i = 0; i < post.size(); i++) {
        std::cout << post[i] << (i + 1 < post.size() ? ' ' : '\n');
    }

    // 释放内存
    freeTree(root);
    return 0;
}
