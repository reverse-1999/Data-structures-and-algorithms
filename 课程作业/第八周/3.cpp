#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// 读取第一行并拆成整数序列
vector<int> parseInput(const string& line) {
    vector<int> nums;
    stringstream ss(line);
    int x;
    while (ss >> x) nums.push_back(x);
    return nums;
}

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
    return root;
    /********** End **********/
   
}

// 利用前序遍历统计路径和等于 target 的根到叶路径条数
int countPathSum(TreeNode* root, int currentSum, int target) {
    /********** Begin **********/
    //递归解
    if (!root) return 0;
    if (!root->left && !root->right) { // 叶子节点
        return (currentSum + root->data == target) ? 1 : 0;
    }
    return countPathSum(root->left, currentSum + root->data, target) + countPathSum(root->right, currentSum + root->data, target);
    /********** End **********/
}

int main() {
    string line;
    getline(cin, line);

    int target;
    cin >> target;

    vector<int> nums = parseInput(line);
    TreeNode* root = buildTree(nums);

    cout << countPathSum(root, 0, target) << endl;

    return 0;
}