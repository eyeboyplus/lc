#include "./../lc.h"

void recursive(const vector<int> &nums, int cur, vector<int> path, vector<vector<int>> &result) {
    if(cur == nums.size()) {
        result.push_back(path);
        return;
    }
    // 不选
    recursive(nums, cur + 1, path, result);
    // 选择
    path.push_back(nums[cur]);
    recursive(nums, cur + 1, path, result);
    path.pop_back();
}

// 增量构造法
vector<vector<int>> solution(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    recursive(nums, 0, path, result);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}