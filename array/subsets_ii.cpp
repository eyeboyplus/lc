#include "./../lc.h"

void recursive(const vector<int> &nums, int index, vector<int> &path,
vector<vector<int>> &result) {
    result.push_back(path);

    int n = nums.size();
    for(int i = index; i < n; ++i) {
        if(i > index && nums[i] == nums[i - 1]) continue;       // 同一层，相同的数性质一样
        path.push_back(nums[i]);
        recursive(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> solution(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> path;
    recursive(nums, 0, path, result);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}