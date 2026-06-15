#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
    if(candidates[start] > target) return;
    vector<int> dp(target,0);
    int size = candidates.size();
    int res = 0;
    for(int i = start; i < size-1;i++)
    {
        dp[candidates[i]] = 1;
    }
    for(int j = candidates[start];j <= target;j++)
    {
        for(int k = start;k<size-1;k++)
        {
            if(j-candidates[k] >= 0) dp[j] += dp[j-candidates[k]];
        }
    }
    for(int j = 1;j <= target;j++)
    {
        cout<<dp[j]<<' ';
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
