#include "./../lc.h"

void backtrack(vector<int> &candidates, int target, vector<int> &path, 
        vector<vector<int>> &ret, int begin) {
    if(target < 0) return;
    if(target == 0) {
        ret.push_back(path);
        return;
    }
    int n = candidates.size();
    for(int i = begin; i < n && target >= candidates[i]; ++i) {
        path.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], path, ret, i);    // 不是 i+1， 是因为可以一个元素可以重复多次
        path.pop_back();
    }
}

vector<vector<int>> solution(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> path;
    vector<vector<int>> ret;
    backtrack(candidates, target, path, ret, 0);
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}