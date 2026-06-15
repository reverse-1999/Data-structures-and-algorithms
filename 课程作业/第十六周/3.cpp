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
    best_time = 0;
    vector<Node> lands;
    for(int i = 0;i<m;i++)
    {
        
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
