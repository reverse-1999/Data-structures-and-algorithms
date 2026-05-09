#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BinaryHeap
{
public:
    explicit BinaryHeap(); // explicit 关键字的作用就是防止类构造函数的隐式自动转换
    // explicit 关键字只对有一个参数的类构造函数有效, 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的, 所以explicit关键字也就无效 
    explicit BinaryHeap(const vector<int> &items) : array(items.size() + 10), heapsize(items.size())
    {
        for (int i = 0; i < items.size(); i++)
            array[i + 1] = items[i];
        buildHeap();
    };
    bool isEmpty() const
    {
        if (heapsize == 0)
            return true;
        else
            return false;
    };

    void insert(const int &x)
    {
        if (heapsize == array.size() - 1)
            array.resize(array.size() * 2);
        int hole = ++heapsize;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = x;
    };

    void deleteMin()
    {
        if (isEmpty())
            return;
        array[1] = array[heapsize--];
        percolateDown(1);
    }; // 直接删除

    void deleteMin(int &minItem)
    {
        if (isEmpty())
            return;
        minItem = array[1];
        array[1] = array[heapsize--];
        percolateDown(1);
    }; // 删除并返回最小值

    int findmin()
    {
        return array[1];
    };

private:
    int heapsize;      // Number of elements in heap
    vector<int> array; // The heap array

    void buildHeap()
    {
        for (int i = heapsize / 2; i > 0; i--)
            percolateDown(i);

    };
    void percolateDown(int hole)
    {
        if(hole * 2 > heapsize) return;
        int child = hole * 2;
        if(child != heapsize && array[child + 1] < array[child]) child++;
        if(array[child] < array[hole]) {
            array.swap(array[child], array[hole]);
            percolateDown(child);
        }
    }; // 向下过滤
};

int findKthLargest()
{
    vector<int> vec, a;
    int temp, k, i;
    // 输入元素
    while (cin >> temp)
    {
        vec.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    // 输入需要寻找的第k个最大元素
    cin >> k;
    // 读入k个元素，建一个最小堆
    for (i = 0; i < k; i++)
    {
        a.push_back(vec[i]);
    }
    BinaryHeap minheap(a);

    // 对于剩下元素，如果比根节点大，插入此元素，删除根节点
    for (i = k; i < vec.size(); i++)
    {
        if (vec[i] > minheap.findmin())
        {
            minheap.insert(vec[i]);
            minheap.deleteMin();
        }
        else
            continue;
    }
    return minheap.findmin();
}
int main()
{
    cout << findKthLargest() << endl;
    system("pause");
    return 0;
}
