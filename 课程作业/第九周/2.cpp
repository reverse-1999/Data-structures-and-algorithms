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

        // 逐步合并，构建哈夫曼树的非叶子节点
        for (; index < 2 * leafSize - 1; index++) {
            int min1, min2;
            findTwoMin(index, min1, min2);

            HFMTree[index].w = HFMTree[min1].w + HFMTree[min2].w;
            HFMTree[index].lchild = min1;
            HFMTree[index].rchild = min2;
            HFMTree[index].parent = -1;

            HFMTree[min1].parent = index;
            HFMTree[min2].parent = index;
        }

        for(int i = 0;i<leafSize;i++) {
            string code = "";
            int current = i;
            while(HFMTree[current].parent != -1) { 
                int parent = HFMTree[current].parent;
                if(HFMTree[parent].lchild == current) {
                    code += "0";
                } else {
                    code += "1";
                }
                current = parent;
            }
            HFMTree[i].code = code;
        }
        // 叶子结点的编码已经由父结点链回溯生成
    }

    

    // 生成并输出原始字符串的Huffman编码
    void getcode(string str) {
        string codeMap[256];
        for (int i = 0; i < leafSize; i++) {
            codeMap[(unsigned char)HFMTree[i].ch] = HFMTree[i].code;
        }

        for (char c : str) {
            string code = codeMap[(unsigned char)c];
            for (int i = (int)code.size() - 1; i >= 0; i--) {
                cout << code[i];
            }
        }
        cout << endl;
    }

    // Huffman译码函数
    void decode(string code) {
        string decodedString = "";

        // 从根结点开始按 0/1 向左或向右下探，落到叶子结点就输出一个字符
        int current = 2 * leafSize - 2;  // 从根节点开始
        for (char c : code) {
            if (c == '0') {
                current = HFMTree[current].lchild;
            } else {
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
    void findTwoMin(int limit, int &min1, int &min2) {
        min1 = -1;
        min2 = -1;

        for (int i = 0; i < limit; i++) {
            if (HFMTree[i].parent != -1) continue;

            if (min1 == -1 || HFMTree[i].w < HFMTree[min1].w) {
                min2 = min1;
                min1 = i;
            } else if (min2 == -1 || HFMTree[i].w < HFMTree[min2].w) {
                min2 = i;
            }
        }
    }

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