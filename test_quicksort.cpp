#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
// ====== 你的 Partition 和 QuickSort ======
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int l = low;
    int r = high - 1;
    while(l <= r)
    {
        while(arr[l]<pivot){
            l++;
        }
        while(arr[r]>=pivot && l < r){
            r--;
        }
        if(l < r)
        {
            swap(arr[l],arr[r]);
        }
        if(l == r)
        {
            swap(arr[l],arr[high]);
            return l;
        }
    }
    return l;
}
void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}
// ========================================

bool doTest(int arr[], int n, int expected[], const char* name)
{
    int* copy = new int[n];
    memcpy(copy, arr, n * sizeof(int));
    QuickSort(copy, 0, n - 1);
    bool ok = true;
    for (int i = 0; i < n; i++) if (copy[i] != expected[i]) { ok = false; break; }
    cout << (ok ? "✅ " : "❌ ") << name << ": ";
    for (int i = 0; i < n; i++) cout << copy[i] << (i+1<n?" ":"");
    if (!ok) {
        cout << "  (期望: ";
        for (int i = 0; i < n; i++) cout << expected[i] << (i+1<n?" ":"");
        cout << ")";
    }
    cout << endl;
    delete[] copy;
    return ok;
}

int main()
{
    int pass = 0, fail = 0;

    int a1[] = {1, 2};          int e1[] = {1, 2};
    if (doTest(a1, 2, e1, "[1,2]")) pass++; else fail++;

    int a2[] = {2, 1};          int e2[] = {1, 2};
    if (doTest(a2, 2, e2, "[2,1]")) pass++; else fail++;

    int a3[] = {1};             int e3[] = {1};
    if (doTest(a3, 1, e3, "[1]")) pass++; else fail++;

    int a4[] = {2,2,2,2};       int e4[] = {2,2,2,2};
    if (doTest(a4, 4, e4, "[2,2,2,2]")) pass++; else fail++;

    int a5[] = {5,4,3,2,1};     int e5[] = {1,2,3,4,5};
    if (doTest(a5, 5, e5, "[5,4,3,2,1]")) pass++; else fail++;

    int a6[] = {1,2,3,4,5};     int e6[] = {1,2,3,4,5};
    if (doTest(a6, 5, e6, "[1,2,3,4,5]")) pass++; else fail++;

    int a7[] = {3,1,4,1,5,9,2,6}; int e7[] = {1,1,2,3,4,5,6,9};
    if (doTest(a7, 8, e7, "[3,1,4,1,5,9,2,6]")) pass++; else fail++;

    int a8[] = {3,0,4,1,2};     int e8[] = {0,1,2,3,4};
    if (doTest(a8, 5, e8, "[3,0,4,1,2]")) pass++; else fail++;

    int a9[] = {3,2,1};         int e9[] = {1,2,3};
    if (doTest(a9, 3, e9, "[3,2,1]")) pass++; else fail++;

    int a10[] = {4,3,2,1,0};    int e10[] = {0,1,2,3,4};
    if (doTest(a10, 5, e10, "[4,3,2,1,0]")) pass++; else fail++;

    int a11[] = {2,1,3,6,5,4};  int e11[] = {1,2,3,4,5,6};
    if (doTest(a11, 6, e11, "[2,1,3,6,5,4]")) pass++; else fail++;

    int a12[] = {6,4,5,1,2,3};  int e12[] = {1,2,3,4,5,6};
    if (doTest(a12, 6, e12, "[6,4,5,1,2,3]")) pass++; else fail++;

    int a13[] = {3,6,2,5,1,4};  int e13[] = {1,2,3,4,5,6};
    if (doTest(a13, 6, e13, "[3,6,2,5,1,4]")) pass++; else fail++;

    int a14[] = {9,8,7,6,5,4,3,2,1,0}; int e14[] = {0,1,2,3,4,5,6,7,8,9};
    if (doTest(a14, 10, e14, "[9..0]")) pass++; else fail++;

    int a15[] = {0,1,2,3,4,5,6,7,8,9}; int e15[] = {0,1,2,3,4,5,6,7,8,9};
    if (doTest(a15, 10, e15, "[0..9]")) pass++; else fail++;

    int a16[] = {2,3,1};        int e16[] = {1,2,3};
    if (doTest(a16, 3, e16, "[2,3,1]")) pass++; else fail++;

    int a17[] = {1,3,2};        int e17[] = {1,2,3};
    if (doTest(a17, 3, e17, "[1,3,2]")) pass++; else fail++;

    cout << "\n通过: " << pass << "/" << (pass+fail);
    if (fail > 0) cout << "  ❌ 失败: " << fail;
    cout << endl;
    return fail > 0 ? 1 : 0;
}
