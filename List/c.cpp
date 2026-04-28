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
        int freq[256] = { 0 };  // 统计字符频率
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
        for (; index < 2 * n - 1; index++) {
            int min1 = HFMTree[0].w;//最小的两个权重值
            int min2 = HFMTree[1].w;
            for (int i = 0; i < index; i++) {
                if (HFMTree[i].parent == -1) {
                    if (HFMTree[i].w < min1) {
                        min2 = min1;
                        min1 = HFMTree[i].w;
                    }
                    else if (HFMTree[i].w < min2) {
                        min2 = HFMTree[i].w;
                    }
                }
            }
            HFMTree[index].w = min1 + min2;
            HFMTree[index].lchild = min1;
            HFMTree[index].rchild = min2;
            HFMTree[index].parent = -1;
            for (int i = 0; i < index; i++) {
                if (HFMTree[i].w == min1 || HFMTree[i].w == min2) {
                    HFMTree[i].parent = index;
                }
            }
        }
        for (int i = 0; i < leafSize; i++) {
            string code = "";
            int current = i;
            while (HFMTree[current].parent != -1) {
                int parent = HFMTree[current].parent;
                if (HFMTree[parent].lchild == current) {
                    code += "0";
                }
                else {
                    code += "1";
                }
                current = parent;
            }
            HFMTree[i].code = code;
        }
        // TODO 完成构建哈夫曼树的代码
    }



    // 生成并输出原始字符串的Huffman编码
    void getcode(string str) {
        // TODO 输出原始字符串对应的Huffman编码
        for (char c : str) {
            for (int i = 0; i < leafSize; i++) {
                if (HFMTree[i].ch == c) {
                    cout << HFMTree[i].code;
                    break;
                }
            }
        }
    }

    // Huffman译码函数
    void decode(string code) {
        string decodedString = "";

        // TODO 完成Huffman译码结果输出函数
        int current = 2 * leafSize - 2;  // 从根节点开始
        for (char c : code) {
            if (c == '0') {
                current = HFMTree[current].lchild;
            }
            else {
                current = HFMTree[current].rchild;
            }
            if (HFMTree[current].lchild == -1 && HFMTree[current].rchild == -1) {
                decodedString += HFMTree[current].ch;
                current = 2 * leafSize - 2;  // 重置到根节点
            }
        }

        cout << decodedString << endl;
    }

private:
    HFMNode* HFMTree;  // Huffman树存储数组 顺序存储
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