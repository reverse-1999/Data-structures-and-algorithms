#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    vector<int> machine_time;
    vector<vector<int>> assignment;
    int level;
    int max_time;

    bool operator>(const Node& other) const {
        return max_time > other.max_time;
    }
};

void solveTaskScheduling(int m, int n, vector<int>& tasks, int& best_time, vector<vector<int>>& best_assignment) {
    best_time = INT_MAX;

    // 将任务按时间降序排列（保留原始索引）
    vector<pair<int, int>> indexed(n);
    for (int i = 0; i < n; i++) indexed[i] = {tasks[i], i};
    sort(indexed.rbegin(), indexed.rend());

    vector<int> times(n), orig(n);
    for (int i = 0; i < n; i++) {
        times[i] = indexed[i].first;
        orig[i] = indexed[i].second;
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    Node start;
    start.machine_time.assign(m, 0);
    start.assignment.resize(m);
    start.level = -1;
    start.max_time = 0;
    pq.push(start);

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.max_time >= best_time) continue;
        if (cur.level == n - 1) {
            best_time = cur.max_time;
            best_assignment.resize(m);
            for (int k = 0; k < m; k++) {
                best_assignment[k].clear();
                for (int x : cur.assignment[k])
                    best_assignment[k].push_back(orig[x]);
            }
            continue;
        }
        int nxt = cur.level + 1;
        int t = times[nxt];
        for (int i = 0; i < m; i++) {
            // 对称剪枝：跳过相同负载的机器
            bool dup = false;
            for (int j = 0; j < i; j++)
                if (cur.machine_time[j] == cur.machine_time[i]) { dup = true; break; }
            if (dup) continue;
            Node child = cur;
            child.machine_time[i] += t;
            child.assignment[i].push_back(nxt);
            child.level = nxt;
            child.max_time = max(cur.max_time, child.machine_time[i]);
            if (child.max_time < best_time) pq.push(child);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    
    int best_time;
    vector<vector<int>> best_assignment;
    solveTaskScheduling(m, n, tasks, best_time, best_assignment);
    
    cout << "最大完成时间：" << best_time << endl;
   
    cout << endl;
    
    
    return 0;
}
