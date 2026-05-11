#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//二叉堆实现
int main() {
    // 读取输入：N个窗口，M个病人，每个病人服务时间T
    int N, M, T;
    cin >> N >> M >> T;
    vector<int> arrival_times(M);
    for (int i = 0; i < M; ++i) {
        cin >> arrival_times[i];
    }
    // windows数组记录每个窗口当前排队的总服务时间
    // counts数组记录每个窗口最终服务的病人数量
    vector<int> windows(N, 0);
    vector<int> counts(N, 0);

    // 处理每个到达的病人
    for (int i = 0; i < M; ++i) {
        int arrival_time = arrival_times[i];
        // 找到最早可用的窗口
        int min_time = windows[0];
        int min_index = 0;
        for (int j = 1; j < N; ++j) {
            if (windows[j] < min_time) {
                min_time = windows[j];
                min_index = j;
            }
        }
        // 更新该窗口的服务时间和病人数量
        if (windows[min_index] < arrival_time) {
            windows[min_index] = arrival_time + T; // 病人到达时窗口空闲，直接服务
        } else {
            windows[min_index] += T; // 病人需要等待，服务时间累加
        }
        counts[min_index]++;
    }
    
    // 输出每个窗口服务的病人数量
    for (int i = 0; i < N; ++i) {
        cout << counts[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}