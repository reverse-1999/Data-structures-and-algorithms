#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// 按“根结点 + 依次输入每个非空结点的左右孩子”的格式建树，-1 表示空结点
TreeNode* buildTree(const vector<int>& nums) {
    /********** Begin **********/
    if (nums.empty()) return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (nums[i] != -1) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        } 
        i++;
        if (i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    
    /********** End **********/
}

// 层序遍历
void levelOrder(TreeNode* root) {
    /********** Begin **********/
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    cout << endl;
    /********** End **********/
}

int main() {
    vector<int> nums;
    int x;

    while (cin >> x) {
        nums.push_back(x);
    }

    TreeNode* root = buildTree(nums);
    levelOrder(root);

    return 0;
}