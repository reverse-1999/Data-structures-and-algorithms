#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 定义Huffman树节点结构体
struct HFMNode {
    int w;          // 权重（字符出现次数）
    char ch;        // 对应的字符（仅叶子节点有效）
    string code;    // Huffman编码（仅叶子节点有效）
    int lchild;     // 左孩子索引
    int rchild;     // 右孩子索引
    int parent;     // 父节点索引
};

class HFMCode {
public:
    // 构造函数：根据输入字符串构建Huffman树
    HFMCode(string str, int n) {
        leafSize = n;  // 叶子节点数（即不同字符数）
        HFMTree = new HFMNode[2 * n - 1];  // 分配节点空间
        int freq[256] = {0};  // 统计字符频率
        for (char c : str) {
            freq[c]++;
        }
        int index = 0;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                HFMTree[index].w = freq[i];
                HFMTree[index].ch = (char)i;
                HFMTree[index].lchild = -1;
                HFMTree[index].rchild = -1;
                HFMTree[index].parent = -1;
                index++;
            }
        }
        int min1, min2;
        for (int i = leafSize; i < 2 * leafSize - 1; i++) {
            min1 = min2 = -1;
            for (int j = 0; j < i; j++) {
                if (HFMTree[j].parent == -1) {
                    if (min1 == -1 || HFMTree[j].w < HFMTree[min1].w) {
                        min2 = min1;
                        min1 = j;
                    } else if (min2 == -1 || HFMTree[j].w < HFMTree[min2].w) {
                        min2 = j;
                    }
                }
            }
            HFMTree[i].w = HFMTree[min1].w + HFMTree[min2].w;
            HFMTree[i].lchild = min1;
            HFMTree[i].rchild = min2;
            HFMTree[i].parent = -1;
            HFMTree[min1].parent = i;
            HFMTree[min2].parent = i;
        }
        
        // TODO 完成构建哈夫曼树的代码
    }

    
    // 生成并输出原始字符串的Huffman编码
    void getcode(string str) {
        
        // TODO 输出原始字符串对应的Huffman编码
        
    }

    // Huffman译码函数
    void decode(string code) {
        string decodedString = "";

        // TODO 完成Huffman译码结果输出函数

        cout << decodedString << endl;
    }

private:
    HFMNode *HFMTree;  // Huffman树存储数组 顺序存储
    int leafSize;      // 叶子节点数量（即不同字符数）
};

int main() {
    int N;
    cin >> N;  // 读取字符种类数
    string str;
    cin >> str;  // 读取原始字符串
    string encodedString;
    cin >> encodedString;  // 读取需要解码的01串
    
    HFMCode hfmtree(str, N);  // 构建Huffman树
    hfmtree.getcode(str);     // 输出编码结果
    hfmtree.decode(encodedString); // 输出解码结果
    
    return 0;
}