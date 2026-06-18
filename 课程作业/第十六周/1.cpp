#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > target) break;
        path.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i, path, result);
        path.pop_back();
    }
}

int main() {
    int target, n;
    cin >> target;
    cin >> n;
    
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    
    sort(candidates.begin(), candidates.end());
    auto last = unique(candidates.begin(), candidates.end());
    candidates.erase(last, candidates.end());
    
    vector<vector<int>> result;
    vector<int> path;
    
    backtrack(candidates, target, 0, path, result);
    
    if (result.empty()) {
        cout << "No solution" << endl;
    } else {
        sort(result.begin(), result.end());
        for (auto& comb : result) {
            for (int j = 0; j < comb.size(); j++) {
                cout << comb[j];
                if (j < comb.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
